#include "qiArdlib.h"
#define PWM_Pin_1 PB1 //TIM 1 3 8
void setup()
{
  // put your setup code here, to run once:

  // Set the port function, output or input.
  pinMode(PWM_Pin_1, PWM);
}

void loop()
{
  analogWrite(PWM_Pin_1, 100);
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