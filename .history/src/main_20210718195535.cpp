#include "qiArdlib.h"


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600); //使用9600的波特率进行串口通讯
}

void loop()
{
pinMode(ADC_Pin, INPUT_ANALOG);
    uint16_t ADC_Val = analogRead(ADC_Pin);
    Serial.printf("ADC_Pin ADC Val is:%d\r\n", ADC_Val);
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
