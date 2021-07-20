#include "qiArdlib.h"
#define PWM_Pin_1 PB1
#define PWM_Pin_2 PC6

void setup()
{
    // put your setup code here, to run once:
    pinMode(PWM_Pin_1, PWM);
    pinMode(PWM_Pin_2, PWM);

    analogWrite(PWM_Pin_1,800);
    analogWrite(PWM_Pin_2,300);
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
