/******************************************************************************
 * The MIT License
 *
 * Copyright (c) 2010, LeafLabs, LLC.
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *****************************************************************************/


#include "qiArdlib.h"
#include "libmaple_types.h"
#include "wirish_math.h"

/*
 * Note on Arduino compatibility:
 *
 * In the Arduino implementation, PWM is done "by hand" in the sense
 * that timer channels are hijacked in groups and an ISR is set which
 * toggles Servo::attach()ed pins using digitalWrite().
 *
 * While this scheme allows any pin to drive a servo, it chews up
 * cycles and complicates the programmer's notion of when a particular
 * timer channel will be in use.
 *
 * This implementation only allows Servo instances to attach() to pins
 * that already have a timer channel associated with them, and just
 * uses pwmWrite() to drive the wave.
 *
 * This introduces an incompatibility: while the Arduino
 * implementation of attach() returns the affected channel on success
 * and 0 on failure, this one returns true on success and false on
 * failure.
 *
 * RC Servos expect a pulse every 20ms.  Since periods are set for
 * entire timers, rather than individual channels, attach()ing a Servo
 * to a pin can interfere with other pins associated with the same
 * timer.  As always, your board's pin map is your friend.
 */

// Pin number of unattached pins
#define NOT_ATTACHED                    (-1)
// Default min/max pulse widths (in microseconds) and angles (in
// degrees).  Values chosen for Arduino compatibility.  These values
// are part of the public API; DO NOT CHANGE THEM.
#define SERVO_DEFAULT_MIN_PW            544
#define SERVO_DEFAULT_MAX_PW            2400
#define SERVO_DEFAULT_MIN_ANGLE         0
#define SERVO_DEFAULT_MAX_ANGLE         180
/** Class for interfacing with RC servomotors. */
class Servo {
public:
    /**
     * @brief Construct a new Servo instance.
     *
     * The new instance will not be attached to any pin.
     */
    Servo();

    /**
     * @brief Associate this instance with a servomotor whose input is
     *        connected to pin.
     *
     * If this instance is already attached to a pin, it will be
     * detached before being attached to the new pin. This function
     * doesn't detach any interrupt attached with the pin's timer
     * channel.
     *
     * @param pin Pin connected to the servo pulse wave input. This
     *            pin must be capable of PWM output.
     *
     * @param minPulseWidth Minimum pulse width to write to pin, in
     *                      microseconds.  This will be associated
     *                      with a minAngle degree angle.  Defaults to
     *                      SERVO_DEFAULT_MIN_PW = 544.
     *
     * @param maxPulseWidth Maximum pulse width to write to pin, in
     *                      microseconds.  This will be associated
     *                      with a maxAngle degree angle. Defaults to
     *                      SERVO_DEFAULT_MAX_PW = 2400.
     *
     * @param minAngle Target angle (in degrees) associated with
     *                 minPulseWidth.  Defaults to
     *                 SERVO_DEFAULT_MIN_ANGLE = 0.
     *
     * @param maxAngle Target angle (in degrees) associated with
     *                 maxPulseWidth.  Defaults to
     *                 SERVO_DEFAULT_MAX_ANGLE = 180.
     *
     * @sideeffect May set pinMode(pin, PWM).
     *
     * @return true if successful, false when pin doesn't support PWM.
     */
    bool attach(uint8 pin,
                uint16 minPulseWidth=SERVO_DEFAULT_MIN_PW,
                uint16 maxPulseWidth=SERVO_DEFAULT_MAX_PW,
                int16 minAngle=SERVO_DEFAULT_MIN_ANGLE,
                int16 maxAngle=SERVO_DEFAULT_MAX_ANGLE);

    /**
     * @brief Check if this instance is attached to a servo.
     * @return true if this instance is attached to a servo, false otherwise.
     * @see Servo::attachedPin()
     */
    bool attached() const { return this->pin != NOT_ATTACHED; }

    /**
     * @brief Get the pin this instance is attached to.
     * @return Pin number if currently attached to a pin, NOT_ATTACHED
     *         otherwise.
     * @see Servo::attach()
     */
    int attachedPin() const { return this->pin; }

    /**
     * @brief Stop driving the servo pulse train.
     *
     * If not currently attached to a motor, this function has no effect.
     *
     * @return true if this call did anything, false otherwise.
     */
    bool detach();

    /**
     * @brief Set the servomotor target angle.
     *
     * @param angle Target angle, in degrees.  If the target angle is
     *              outside the range specified at attach() time, it
     *              will be clamped to lie in that range.
     *
     * @see Servo::attach()
     */
    void write(int degrees);
	void write(float degrees);

    /**
     * Get the servomotor's target angle, in degrees.  This will
     * lie inside the range specified at attach() time.
     *
     * @see Servo::attach()
     */
    int read() const;
	float read_f() const;

    /**
     * @brief Set the pulse width, in microseconds.
     *
     * @param pulseWidth Pulse width to send to the servomotor, in
     *                   microseconds. If outside of the range
     *                   specified at attach() time, it is clamped to
     *                   lie in that range.
     *
     * @see Servo::attach()
     */
    void writeMicroseconds(uint16 pulseWidth);
	void writeMicroseconds(float pulseWidth);

    /**
     * Get the current pulse width, in microseconds.  This will
     * lie within the range specified at attach() time.
     *
     * @see Servo::attach()
     */
    uint16 readMicroseconds() const;
	float readMicroseconds_f() const;

private:
    int16 pin;
    uint16 minPW;
    uint16 maxPW;
    int16 minAngle;
    int16 maxAngle;

    void resetFields(void);
};









#define __Map(x,in_min,in_max,out_min,out_max) \
    ((x-in_min)*(out_max-out_min)/(in_max-in_min)+out_min)

// 20 millisecond period config.  For a 1-based prescaler,
//
//    (prescaler * overflow / CYC_MSEC) msec = 1 timer cycle = 20 msec
// => prescaler * overflow = 20 * CYC_MSEC
//
// This picks the smallest prescaler that allows an overflow < 2^16.
#define MAX_OVERFLOW    ((1 << 16) - 1)
#define CYC_MSEC        (1000.0f * CYCLES_PER_MICROSECOND)
#define TAU_MSEC        20.0f//@Frequency = 50Hz
#define TAU_USEC        (TAU_MSEC * 1000.0f)
#define TAU_CYC         (TAU_MSEC * CYC_MSEC)
#define SERVO_PRESCALER (uint16_t)(TAU_CYC / (double)MAX_OVERFLOW + 1.0f)
#define SERVO_OVERFLOW  ((uint16_t)round((double)TAU_CYC / SERVO_PRESCALER))

// Unit conversions
#define US_TO_COMPARE(us) ((uint16_t)__Map((us), 0, TAU_USEC, 0, SERVO_OVERFLOW))
#define COMPARE_TO_US(c)  ((uint32_t)__Map((c), 0, SERVO_OVERFLOW, 0, TAU_USEC))
#define ANGLE_TO_US(a)    ((uint16_t)(__Map((a), this->minAngle, this->maxAngle, \
                                        this->minPW, this->maxPW)))
#define US_TO_ANGLE(us)   ((int16_t)(__Map((us), this->minPW, this->maxPW,  \
                                       this->minAngle, this->maxAngle)))
										   
// Unit conversions	(float)
#define US_TO_COMPARE_F(us) ((float)__Map((us), 0, TAU_USEC, 0, SERVO_OVERFLOW))
#define COMPARE_TO_US_F(c)  ((float)__Map((c), 0, SERVO_OVERFLOW, 0, TAU_USEC))
#define ANGLE_TO_US_F(a)    ((float)(__Map((a), this->minAngle, this->maxAngle, \
                                        this->minPW, this->maxPW)))
#define US_TO_ANGLE_F(us)   ((float)(__Map((us), this->minPW, this->maxPW,  \
                                       this->minAngle, this->maxAngle)))

Servo::Servo() {
    this->resetFields();
}

bool Servo::attach(uint8 pin,
                   uint16 minPW,
                   uint16 maxPW,
                   int16 minAngle,
                   int16 maxAngle) {
    TIM_TypeDef* tdev = PIN_MAP[pin].TIMx;

    if (tdev == NULL) {
        // don't reset any fields or ASSERT(0), to keep driving any
        // previously attach()ed servo.
        return false;
    }

    if (this->attached()) {
        this->detach();
    }

    this->pin = pin;
    this->minPW = minPW;
    this->maxPW = maxPW;
    this->minAngle = minAngle;
    this->maxAngle = maxAngle;

    pinMode(pin, PWM);

    TIM_Cmd(tdev,DISABLE);
    timer_set_prescaler(tdev, SERVO_PRESCALER - 1); // prescaler is 1-based
    timer_set_reload(tdev, SERVO_OVERFLOW);
    timer_generate_update(tdev);
    TIM_Cmd(tdev,ENABLE);

    return true;
}

bool Servo::detach() {
    if (!this->attached()) {
        return false;
    }

    TIM_TypeDef* tdev = PIN_MAP[this->pin].TIMx;
    uint8 tchan = PIN_MAP[this->pin].TimerChannel;
    //timer_set_mode(tdev, tchan, DISABLE);
	TIM_CCxCmd(tdev, tchan, TIM_CCx_Disable);
    this->resetFields();

    return true;
}

void Servo::write(int degrees) {
    degrees = constrain(degrees, this->minAngle, this->maxAngle);
    this->writeMicroseconds(ANGLE_TO_US(degrees));
}

void Servo::write(float degrees) {
    degrees = constrain(degrees, this->minAngle, this->maxAngle);
    this->writeMicroseconds(ANGLE_TO_US_F(degrees));
}

int Servo::read() const {
    int a = US_TO_ANGLE(this->readMicroseconds());
    // map() round-trips in a weird way we mostly correct for here;
    // the round-trip is still sometimes off-by-one for write(1) and
    // write(179).
    return a == this->minAngle || a == this->maxAngle ? a : a + 1;
}

float Servo::read_f() const {
    int a = US_TO_ANGLE_F(this->readMicroseconds_f());
    // map() round-trips in a weird way we mostly correct for here;
    // the round-trip is still sometimes off-by-one for write(1) and
    // write(179).
    return a == this->minAngle || a == this->maxAngle ? a : a + 1;
}

void Servo::writeMicroseconds(uint16 pulseWidth) {
    if (!this->attached()) {
        //ASSERT(0);
        return;
    }

    pulseWidth = constrain(pulseWidth, this->minPW, this->maxPW);
    pwmWrite(this->pin, US_TO_COMPARE(pulseWidth));
}

void Servo::writeMicroseconds(float pulseWidth) {
    if (!this->attached()) {
        //ASSERT(0);
        return;
    }

    pulseWidth = constrain(pulseWidth, this->minPW, this->maxPW);
    pwmWrite(this->pin, US_TO_COMPARE_F(pulseWidth));
}

uint16 Servo::readMicroseconds() const {
    if (!this->attached()) {
        //ASSERT(0);
        return 0;
    }
		
    uint16 compare = timer_get_compare(PIN_MAP[this->pin].TIMx,
                                       PIN_MAP[this->pin].TimerChannel);

    return COMPARE_TO_US(compare);
}

float Servo::readMicroseconds_f() const {
    if (!this->attached()) {
        //ASSERT(0);
        return 0;
    }
		
    uint16 compare = timer_get_compare(PIN_MAP[this->pin].TIMx,
                                       PIN_MAP[this->pin].TimerChannel);

    return COMPARE_TO_US_F(compare);
}

void Servo::resetFields(void) {
    this->pin = NOT_ATTACHED;
    this->minAngle = SERVO_DEFAULT_MIN_ANGLE;
    this->maxAngle = SERVO_DEFAULT_MAX_ANGLE;
    this->minPW = SERVO_DEFAULT_MIN_PW;
    this->maxPW = SERVO_DEFAULT_MAX_PW;
}
