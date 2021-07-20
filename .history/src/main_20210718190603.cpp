#include "qiArdlib.h"

#define PWM_Pin_1 PB1 //TIM 1 3 8 PC+ PC-接GND

#define K_1 28
#define K_2 29
#define K_3 31
#define K_4 33
#define K_5 35
#define K_6 37
#define K_7 39
#define K_8 41
#define K_9 44
#define K_10 46
#define K_11 49
#define K_12 52
#define K_13 55
#define K_14 58
#define K_15 62
#define K_16 65
#define K_17 69
#define K_18 73
#define K_19 78
#define K_20 82
#define K_21 87
#define K_22 92
#define K_23 98
#define K_24 104
#define K_25 110
#define K_26 117
#define K_27 123
#define K_28 131
#define K_29 139
#define K_30 147
#define K_31 156
#define K_32 165
#define K_33 175
#define K_34 185
#define K_35 196
#define K_36 208
#define K_37 220
#define K_38 233
#define K_39 247
#define K_40 262
#define K_41 277
#define K_42 294
#define K_43 311
#define K_44 330
#define K_45 349
#define K_46 370
#define K_47 392
#define K_48 415
#define K_49 440
#define K_50 466
#define K_51 494
#define K_52 523
#define K_53 554
#define K_54 587
#define K_55 622
#define K_56 659
#define K_57 698
#define K_58 740
#define K_59 784
#define K_60 831
#define K_61 880
#define K_62 932
#define K_63 988
#define K_64 1047
#define K_65 1109
#define K_66 1175
#define K_67 1245
#define K_68 1319
#define K_69 1397
#define K_70 1480
#define K_71 1568
#define K_72 1661
#define K_73 1760
#define K_74 1865
#define K_75 1976
#define K_76 2093
#define K_77 2217
#define K_78 2349
#define K_79 2489
#define K_80 2637
#define K_81 2794
#define K_82 2960
#define K_83 3136
#define K_84 3322
#define K_85 3520
#define K_86 3729
#define K_87 3951
#define K_88 4186

void setup()
{
    // put your setup code here, to run once:
    pinMode(PWM_Pin_1, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    //toneBlock_Volumn_us(PWM_Pin_1, 200, 10,1);
    while (Serial.available() > 0)
    {
        if (Serial.read() == 1)
        {
            toneBlock_Volumn_us(K_1, 200, 10, 1);
        }
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
