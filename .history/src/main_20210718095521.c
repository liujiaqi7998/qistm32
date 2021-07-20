#include "qiArdlib.h"
#define LED_Pin PB1

void setup()
{
    // put your setup code here, to run once:
    pinMode(LED_Pin, OUTPUT);
}

void loop()
{
    // put your main code here, to run repeatedly:
    digitalWrite(LED_Pin, HIGH);
    delay(5000);
    digitalWrite(LED_Pin, LOW);
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
