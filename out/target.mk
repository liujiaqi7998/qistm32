###########################################################################
#  !!! This file is Auto-Generated By Embedded IDE, Don't modify it !!!
###########################################################################

# eide version
EIDE_VER = 2

# current target
CUR_TARGET := Debug

# current compiler
COMPILER_TYPE := AC5

# include folders
INCLUDE_FOLDERS += .eide/deps
INCLUDE_FOLDERS += lib/CMSIS
INCLUDE_FOLDERS += src
INCLUDE_FOLDERS += hal/STM32F10x_StdPeriph_Driver
INCLUDE_FOLDERS += hal/STM32F10x_StdPeriph_Driver/src
INCLUDE_FOLDERS += hal/STM32F10x_StdPeriph_Driver/inc
INCLUDE_FOLDERS += ArduinoAPI
INCLUDE_FOLDERS += ArduinoAPI/avr
INCLUDE_FOLDERS += Core

# library search folders

# c source files
C_SOURCES += ArduinoAPI/dtostrf.c
C_SOURCES += ArduinoAPI/itoa.c
C_SOURCES += ArduinoAPI/qiArdlib.c
C_SOURCES += Core/adc.c
C_SOURCES += Core/delay.c
C_SOURCES += Core/exti.c
C_SOURCES += Core/gpio.c
C_SOURCES += Core/pwm.c
C_SOURCES += Core/timer.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/misc.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_adc.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_exti.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_spi.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_tim.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c
C_SOURCES += hal/STM32F10x_StdPeriph_Driver/system_stm32f10x.c

# cpp source files
CPP_SOURCES += ArduinoAPI/HardwareSerial.cpp
CPP_SOURCES += ArduinoAPI/IPAddress.cpp
CPP_SOURCES += ArduinoAPI/Print.cpp
CPP_SOURCES += ArduinoAPI/SPI.cpp
CPP_SOURCES += ArduinoAPI/Stream.cpp
CPP_SOURCES += ArduinoAPI/Tone.cpp
CPP_SOURCES += ArduinoAPI/WMath.cpp
CPP_SOURCES += ArduinoAPI/WString.cpp
CPP_SOURCES += ArduinoAPI/Wire.cpp
CPP_SOURCES += ArduinoAPI/WireBase.cpp
CPP_SOURCES += ArduinoAPI/new.cpp
CPP_SOURCES += src/main.cpp

# asm source files
ASM_SOURCES += src/startup_stm32f10x_md.s

# object files

# macro defines
DEFINES += USE_STDPERIPH_DRIVER
DEFINES += STM32F10X_HD