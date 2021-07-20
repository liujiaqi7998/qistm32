#include "qiArdlib.h"
#define LED_Pin PB1

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED_Pin, PWM);
}

void loop()
{
    // put your main code here, to run repeatedly:
    analogWrite(LED_Pin,100);
}

/**
  * @brief  Main Function
  * @param  None
  * @retval None
  */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    Delay_Init();
    setup();
    for (;;)
        loop();
}
