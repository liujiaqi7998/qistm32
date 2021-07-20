#include "qiArdlib.h"
#define AD_Pin_1 PA0 //ADC1
void setup()
{
  // put your setup code here, to run once:

  // Set the port function, output or input.
  pinMode(AD_Pin_1, OUTPUT);
}

void loop()
{
  analogWrite(AD_Pin_1, 100);
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