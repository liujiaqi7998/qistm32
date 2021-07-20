#include "qiArdlib.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8 PC+ PC-接GND

void setup()
{
}

void loop()
{
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
