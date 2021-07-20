#include "qiArdlib.h"
#include "Servo.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8
Servo myservo;
int pos = 0; // variable to store the servo position
void setup()
{
    // put your setup code here, to run once:
    myservo.attach(PWM_Pin_1);
}

void loop()
{
    for (pos = 0; pos < 180; pos += 1) // goes from 0 degrees to 180 degrees
    {                                  // in steps of 1 degree
        myservo.write(pos);            // tell servo to go to position in variable 'pos'
        delay(15);                     // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 1; pos -= 1) // goes from 180 degrees to 0 degrees
    {
        myservo.write(pos); // tell servo to go to position in variable 'pos'
        delay(15);          // waits 15ms for the servo to reach the position
    }
}

/**
  * @brief  Main Function
  * @param  None
  * @retval None
  */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    SysClock_Init(F_CPU_72MHz);
    Delay_Init();
    setup();
    for (;;)
        loop();
}
