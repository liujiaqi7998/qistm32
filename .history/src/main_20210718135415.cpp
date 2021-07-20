#include "qiArdlib.h"
#include "Servo.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8

Servo myservo;
int pos = 0; // variable to store the servo position
void setup()
{
    // put your setup code here, to run once:
    myservo.attach(PWM_Pin_1);
    myservo.write(50);
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
