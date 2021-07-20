#include "qiArdlib.h"
#define PWM_Pin_1 PB1 //TIM 1 3 8
#define PWM_Pin_2 PC6 //TIM 3 8
#define PWM_Pin_3 PA9 //
void setup()
{
    // put your setup code here, to run once:
    pinMode(PWM_Pin_1, PWM);
    pinMode(PWM_Pin_2, PWM);
    pinMode(PWM_Pin_3, PWM);
    analogWrite(PWM_Pin_1, 800);
    analogWrite(PWM_Pin_2, 500);
    analogWrite(PWM_Pin_3, 100);
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
