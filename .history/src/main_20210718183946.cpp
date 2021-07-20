#include "qiArdlib.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8 PC+ PC-接GND
#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493  //指定频率

void setup()
{
    // put your setup code here, to run once:
    pinMode(PWM_Pin_1, PWM);
    analogWrite(PWM_Pin_1, 900);

}

void loop()
{
    //toneBlock_Volumn_us(PWM_Pin_1, 200, 10,1);
    
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
