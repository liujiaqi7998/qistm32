#include "qiArdlib.h"
#define AD_Pin_1 PA1 //ADC1
void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600); //使用9600的波特率进行串口通讯
  Serial.print("OK");
  pinMode(AD_Pin_1,INPUT_ANALOG);
}

void loop()
{
  int n = analogRead(AD_Pin_1); //读取模拟口的数值,因为ATmega 2560 AD精度为10位，故返回值范围为0~1023
  n = n * 4.888;             //将返回值换算成毫伏
  Serial.print("The Voltage Value is(mv):");
  Serial.println(n, DEC); //DEC在这里是设置输出数据的格式，此处可省略，详见http://kb.open.eefocus.com/index.php?title=Serial
  delay(1000);
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
