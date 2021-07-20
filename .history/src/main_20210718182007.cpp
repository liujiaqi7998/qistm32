#include "qiArdlib.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8 PC+ PC-接GND

void setup()
{
    // put your setup code here, to run once:
    pinMode(PWM_Pin_1, PWM);
    tone(PWM_Pin_1, 262, 10);
    tone(PWM_Pin_1, 294, 10);
    tone(PWM_Pin_1, NOTE_E5, 10);
    tone(PWM_Pin_1, NOTE_F5, 10);
    tone(PWM_Pin_1, NOTE_G5, 10);
    tone(PWM_Pin_1, NOTE_A5, 10);
    tone(PWM_Pin_1, NOTE_B5, 10);
}

void loop()
{
    // put your main code here, to run repeatedly:
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
