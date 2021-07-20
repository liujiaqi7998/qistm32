#include "qiArdlib.h"
#define ADC_Pin_1 PA1 //ADC1
void setup()
{
Serial.begin(115200);
    pinMode(PA0, INPUT_ANALOG_DMA);
    pinMode(PA1, INPUT_ANALOG_DMA);
    pinMode(PA2, INPUT_ANALOG_DMA);
    pinMode(PA3, INPUT_ANALOG_DMA);
    pinMode(PA4, INPUT_ANALOG_DMA);
    pinMode(PA5, INPUT_ANALOG_DMA);
    pinMode(PA6, INPUT_ANALOG_DMA);
    pinMode(PA7, INPUT_ANALOG_DMA);

    pinMode(PB0, INPUT_ANALOG_DMA);
    pinMode(PB1, INPUT_ANALOG_DMA);

    pinMode(PC0, INPUT_ANALOG_DMA);
    pinMode(PC1, INPUT_ANALOG_DMA);
    pinMode(PC2, INPUT_ANALOG_DMA);
    pinMode(PC3, INPUT_ANALOG_DMA);
    pinMode(PC4, INPUT_ANALOG_DMA);
    pinMode(PC5, INPUT_ANALOG_DMA);
    ADC_DMA_Init();
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
