#include "qiArdlib.h"

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);  //使用9600的波特率进行串口通讯
  Serial2.begin(9600); //使用9600的波特率进行串口通讯
  Serial3.begin(9600); //使用9600的波特率进行串口通讯
  Serial4.begin(9600); //使用9600的波特率进行串口通讯
  Serial5.begin(9600); //使用9600的波特率进行串口通讯
}

void loop()
{
  
  Serial.print("1");

  Serial2.print("2");

  Serial3.print("3");

  Serial4.print("4");

  Serial5.print("5");
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
