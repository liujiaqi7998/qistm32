EIDE_UNIFY_BUILDER := 1
CFLAGS := -c --apcs=interwork --cpu Cortex-M3 --c99 -D__MICROLIB -O0 --split_sections --diag_suppress=1 --diag_suppress=1295 -g -I.\.eide\deps -I.\lib\CMSIS -I.\src -I.\lib\STM32F10x_FWLib -I.\lib\STM32F10x_FWLib\src -I.\lib\STM32F10x_FWLib\inc -I.\lib\Servo -I.\lib\qiArdlib -I.\lib\qiArdlib\avr -I.\lib\Dht11 -I.\lib\Core -DUSE_STDPERIPH_DRIVER -DSTM32F10X_HD
CXXFLAGS := -c --cpp --apcs=interwork --cpu Cortex-M3 -D__MICROLIB -O0 --split_sections --diag_suppress=1 --diag_suppress=1295 -g -I.\.eide\deps -I.\lib\CMSIS -I.\src -I.\lib\STM32F10x_FWLib -I.\lib\STM32F10x_FWLib\src -I.\lib\STM32F10x_FWLib\inc -I.\lib\Servo -I.\lib\qiArdlib -I.\lib\qiArdlib\avr -I.\lib\Dht11 -I.\lib\Core -DUSE_STDPERIPH_DRIVER -DSTM32F10X_HD
ASMFLAGS := --apcs=interwork --cpu Cortex-M3 --pd "__MICROLIB SETA 1" -g -I.\.eide\deps -I.\lib\CMSIS -I.\src -I.\lib\STM32F10x_FWLib -I.\lib\STM32F10x_FWLib\src -I.\lib\STM32F10x_FWLib\inc -I.\lib\Servo -I.\lib\qiArdlib -I.\lib\qiArdlib\avr -I.\lib\Dht11 -I.\lib\Core
LDFLAGS := --cpu Cortex-M3 --library_type=microlib --scatter "e:/singlechip/project/20210718/out/Debug/小奇stm32f103.sct" --strict --summary_stderr --info summarysizes --map --xref --callgraph --symbols --info sizes --info totals --info unused --info veneers --list .\out\Debug\小奇stm32f103.map
LDLIBS := 
