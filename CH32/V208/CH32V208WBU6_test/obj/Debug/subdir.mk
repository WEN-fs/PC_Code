################################################################################
# MRS Version: {"version":"1.8.4","date":"2023/02/015"}
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Debug/debug.c 

OBJS += \
./Debug/debug.o 

C_DEPS += \
./Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
Debug/%.o: ../Debug/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"D:\Users\Lumine\Documents\Code\CH32\V208\CH32V208WBU6_test\Debug" -I"D:\Users\Lumine\Documents\Code\CH32\V208\CH32V208WBU6_test\Core" -I"D:\Users\Lumine\Documents\Code\CH32\V208\CH32V208WBU6_test\User" -I"D:\Users\Lumine\Documents\Code\CH32\V208\CH32V208WBU6_test\Peripheral\inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

