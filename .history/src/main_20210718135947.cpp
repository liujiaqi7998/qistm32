#include "qiArdlib.h"
#include "Servo.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8

Servo myservo;
int pos = 0; // variable to store the servo position
int temp;
void setup()
{
  // put your setup code here, to run once:

  Serial.begin(9600); //使用9600的波特率进行串口通讯
  myservo.attach(PWM_Pin_1);
  myservo.write(50);
}

void loop()
{
  if (Serial.available() > 0)
  {
    char serialDate = Serial.read();
    Serial.print(serialDate);
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
