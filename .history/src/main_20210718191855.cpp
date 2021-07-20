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
        if (Serial.available() > 0)
        {
            char serialDate = Serial.read();
            if (serialDate == 1)
            {
                toneBlock_Volumn_us(PWM_Pin_1,K_1, 500000, 1);
            }
if (serialDate == 2)
            {
                toneBlock_Volumn_us(PWM_Pin_2,K_2, 500000, 2);
            }
if (serialDate == 3)
            {
                toneBlock_Volumn_us(PWM_Pin_3,K_3, 500000, 3);
            }
if (serialDate == 4)
            {
                toneBlock_Volumn_us(PWM_Pin_4,K_4, 500000, 4);
            }
if (serialDate == 5)
            {
                toneBlock_Volumn_us(PWM_Pin_5,K_5, 500000, 5);
            }
if (serialDate == 6)
            {
                toneBlock_Volumn_us(PWM_Pin_6,K_6, 500000, 6);
            }
if (serialDate == 7)
            {
                toneBlock_Volumn_us(PWM_Pin_7,K_7, 500000, 7);
            }
if (serialDate == 8)
            {
                toneBlock_Volumn_us(PWM_Pin_8,K_8, 500000, 8);
            }
if (serialDate == 9)
            {
                toneBlock_Volumn_us(PWM_Pin_9,K_9, 500000, 9);
            }
if (serialDate == 10)
            {
                toneBlock_Volumn_us(PWM_Pin_10,K_10, 500000, 10);
            }
if (serialDate == 11)
            {
                toneBlock_Volumn_us(PWM_Pin_11,K_11, 500000, 11);
            }
if (serialDate == 12)
            {
                toneBlock_Volumn_us(PWM_Pin_12,K_12, 500000, 12);
            }
if (serialDate == 13)
            {
                toneBlock_Volumn_us(PWM_Pin_13,K_13, 500000, 13);
            }
if (serialDate == 14)
            {
                toneBlock_Volumn_us(PWM_Pin_14,K_14, 500000, 14);
            }
if (serialDate == 15)
            {
                toneBlock_Volumn_us(PWM_Pin_15,K_15, 500000, 15);
            }
if (serialDate == 16)
            {
                toneBlock_Volumn_us(PWM_Pin_16,K_16, 500000, 16);
            }
if (serialDate == 17)
            {
                toneBlock_Volumn_us(PWM_Pin_17,K_17, 500000, 17);
            }
if (serialDate == 18)
            {
                toneBlock_Volumn_us(PWM_Pin_18,K_18, 500000, 18);
            }
if (serialDate == 19)
            {
                toneBlock_Volumn_us(PWM_Pin_19,K_19, 500000, 19);
            }
if (serialDate == 20)
            {
                toneBlock_Volumn_us(PWM_Pin_20,K_20, 500000, 20);
            }
if (serialDate == 21)
            {
                toneBlock_Volumn_us(PWM_Pin_21,K_21, 500000, 21);
            }
if (serialDate == 22)
            {
                toneBlock_Volumn_us(PWM_Pin_22,K_22, 500000, 22);
            }
if (serialDate == 23)
            {
                toneBlock_Volumn_us(PWM_Pin_23,K_23, 500000, 23);
            }
if (serialDate == 24)
            {
                toneBlock_Volumn_us(PWM_Pin_24,K_24, 500000, 24);
            }
if (serialDate == 25)
            {
                toneBlock_Volumn_us(PWM_Pin_25,K_25, 500000, 25);
            }
if (serialDate == 26)
            {
                toneBlock_Volumn_us(PWM_Pin_26,K_26, 500000, 26);
            }
if (serialDate == 27)
            {
                toneBlock_Volumn_us(PWM_Pin_27,K_27, 500000, 27);
            }
if (serialDate == 28)
            {
                toneBlock_Volumn_us(PWM_Pin_28,K_28, 500000, 28);
            }
if (serialDate == 29)
            {
                toneBlock_Volumn_us(PWM_Pin_29,K_29, 500000, 29);
            }
if (serialDate == 30)
            {
                toneBlock_Volumn_us(PWM_Pin_30,K_30, 500000, 30);
            }
if (serialDate == 31)
            {
                toneBlock_Volumn_us(PWM_Pin_31,K_31, 500000, 31);
            }
if (serialDate == 32)
            {
                toneBlock_Volumn_us(PWM_Pin_32,K_32, 500000, 32);
            }
if (serialDate == 33)
            {
                toneBlock_Volumn_us(PWM_Pin_33,K_33, 500000, 33);
            }
if (serialDate == 34)
            {
                toneBlock_Volumn_us(PWM_Pin_34,K_34, 500000, 34);
            }
if (serialDate == 35)
            {
                toneBlock_Volumn_us(PWM_Pin_35,K_35, 500000, 35);
            }
if (serialDate == 36)
            {
                toneBlock_Volumn_us(PWM_Pin_36,K_36, 500000, 36);
            }
if (serialDate == 37)
            {
                toneBlock_Volumn_us(PWM_Pin_37,K_37, 500000, 37);
            }
if (serialDate == 38)
            {
                toneBlock_Volumn_us(PWM_Pin_38,K_38, 500000, 38);
            }
if (serialDate == 39)
            {
                toneBlock_Volumn_us(PWM_Pin_39,K_39, 500000, 39);
            }
if (serialDate == 40)
            {
                toneBlock_Volumn_us(PWM_Pin_40,K_40, 500000, 40);
            }
if (serialDate == 41)
            {
                toneBlock_Volumn_us(PWM_Pin_41,K_41, 500000, 41);
            }
if (serialDate == 42)
            {
                toneBlock_Volumn_us(PWM_Pin_42,K_42, 500000, 42);
            }
if (serialDate == 43)
            {
                toneBlock_Volumn_us(PWM_Pin_43,K_43, 500000, 43);
            }
if (serialDate == 44)
            {
                toneBlock_Volumn_us(PWM_Pin_44,K_44, 500000, 44);
            }
if (serialDate == 45)
            {
                toneBlock_Volumn_us(PWM_Pin_45,K_45, 500000, 45);
            }
if (serialDate == 46)
            {
                toneBlock_Volumn_us(PWM_Pin_46,K_46, 500000, 46);
            }
if (serialDate == 47)
            {
                toneBlock_Volumn_us(PWM_Pin_47,K_47, 500000, 47);
            }
if (serialDate == 48)
            {
                toneBlock_Volumn_us(PWM_Pin_48,K_48, 500000, 48);
            }
if (serialDate == 49)
            {
                toneBlock_Volumn_us(PWM_Pin_49,K_49, 500000, 49);
            }
if (serialDate == 50)
            {
                toneBlock_Volumn_us(PWM_Pin_50,K_50, 500000, 50);
            }
if (serialDate == 51)
            {
                toneBlock_Volumn_us(PWM_Pin_51,K_51, 500000, 51);
            }
if (serialDate == 52)
            {
                toneBlock_Volumn_us(PWM_Pin_52,K_52, 500000, 52);
            }
if (serialDate == 53)
            {
                toneBlock_Volumn_us(PWM_Pin_53,K_53, 500000, 53);
            }
if (serialDate == 54)
            {
                toneBlock_Volumn_us(PWM_Pin_54,K_54, 500000, 54);
            }
if (serialDate == 55)
            {
                toneBlock_Volumn_us(PWM_Pin_55,K_55, 500000, 55);
            }
if (serialDate == 56)
            {
                toneBlock_Volumn_us(PWM_Pin_56,K_56, 500000, 56);
            }
if (serialDate == 57)
            {
                toneBlock_Volumn_us(PWM_Pin_57,K_57, 500000, 57);
            }
if (serialDate == 58)
            {
                toneBlock_Volumn_us(PWM_Pin_58,K_58, 500000, 58);
            }
if (serialDate == 59)
            {
                toneBlock_Volumn_us(PWM_Pin_59,K_59, 500000, 59);
            }
if (serialDate == 60)
            {
                toneBlock_Volumn_us(PWM_Pin_60,K_60, 500000, 60);
            }
if (serialDate == 61)
            {
                toneBlock_Volumn_us(PWM_Pin_61,K_61, 500000, 61);
            }
if (serialDate == 62)
            {
                toneBlock_Volumn_us(PWM_Pin_62,K_62, 500000, 62);
            }
if (serialDate == 63)
            {
                toneBlock_Volumn_us(PWM_Pin_63,K_63, 500000, 63);
            }
if (serialDate == 64)
            {
                toneBlock_Volumn_us(PWM_Pin_64,K_64, 500000, 64);
            }
if (serialDate == 65)
            {
                toneBlock_Volumn_us(PWM_Pin_65,K_65, 500000, 65);
            }
if (serialDate == 66)
            {
                toneBlock_Volumn_us(PWM_Pin_66,K_66, 500000, 66);
            }
if (serialDate == 67)
            {
                toneBlock_Volumn_us(PWM_Pin_67,K_67, 500000, 67);
            }
if (serialDate == 68)
            {
                toneBlock_Volumn_us(PWM_Pin_68,K_68, 500000, 68);
            }
if (serialDate == 69)
            {
                toneBlock_Volumn_us(PWM_Pin_69,K_69, 500000, 69);
            }
if (serialDate == 70)
            {
                toneBlock_Volumn_us(PWM_Pin_70,K_70, 500000, 70);
            }
if (serialDate == 71)
            {
                toneBlock_Volumn_us(PWM_Pin_71,K_71, 500000, 71);
            }
if (serialDate == 72)
            {
                toneBlock_Volumn_us(PWM_Pin_72,K_72, 500000, 72);
            }
if (serialDate == 73)
            {
                toneBlock_Volumn_us(PWM_Pin_73,K_73, 500000, 73);
            }
if (serialDate == 74)
            {
                toneBlock_Volumn_us(PWM_Pin_74,K_74, 500000, 74);
            }
if (serialDate == 75)
            {
                toneBlock_Volumn_us(PWM_Pin_75,K_75, 500000, 75);
            }
if (serialDate == 76)
            {
                toneBlock_Volumn_us(PWM_Pin_76,K_76, 500000, 76);
            }
if (serialDate == 77)
            {
                toneBlock_Volumn_us(PWM_Pin_77,K_77, 500000, 77);
            }
if (serialDate == 78)
            {
                toneBlock_Volumn_us(PWM_Pin_78,K_78, 500000, 78);
            }
if (serialDate == 79)
            {
                toneBlock_Volumn_us(PWM_Pin_79,K_79, 500000, 79);
            }
if (serialDate == 80)
            {
                toneBlock_Volumn_us(PWM_Pin_80,K_80, 500000, 80);
            }
if (serialDate == 81)
            {
                toneBlock_Volumn_us(PWM_Pin_81,K_81, 500000, 81);
            }
if (serialDate == 82)
            {
                toneBlock_Volumn_us(PWM_Pin_82,K_82, 500000, 82);
            }
if (serialDate == 83)
            {
                toneBlock_Volumn_us(PWM_Pin_83,K_83, 500000, 83);
            }
if (serialDate == 84)
            {
                toneBlock_Volumn_us(PWM_Pin_84,K_84, 500000, 84);
            }
if (serialDate == 85)
            {
                toneBlock_Volumn_us(PWM_Pin_85,K_85, 500000, 85);
            }
if (serialDate == 86)
            {
                toneBlock_Volumn_us(PWM_Pin_86,K_86, 500000, 86);
            }
if (serialDate == 87)
            {
                toneBlock_Volumn_us(PWM_Pin_87,K_87, 500000, 87);
            }
if (serialDate == 88)
            {
                toneBlock_Volumn_us(PWM_Pin_88,K_88, 500000, 88);
            }

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
