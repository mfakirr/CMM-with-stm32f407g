################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c \
../src/stm32f4xx_it.c \
../src/system_stm32f4xx.c \
../src/usb_bsp.c \
../src/usbd_cdc.c \
../src/usbd_desc.c \
../src/usbd_usr.c 

S_UPPER_SRCS += \
../src/startup_stm32f4xx.S 

OBJS += \
./src/main.o \
./src/startup_stm32f4xx.o \
./src/stm32f4xx_it.o \
./src/system_stm32f4xx.o \
./src/usb_bsp.o \
./src/usbd_cdc.o \
./src/usbd_desc.o \
./src/usbd_usr.o 

S_UPPER_DEPS += \
./src/startup_stm32f4xx.d 

C_DEPS += \
./src/main.d \
./src/stm32f4xx_it.d \
./src/system_stm32f4xx.d \
./src/usb_bsp.d \
./src/usbd_cdc.d \
./src/usbd_desc.d \
./src/usbd_usr.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -ID:/Users/muhammett/Desktop/TEZ/ECLIPSE/WORK_DISCO/CMM/include -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -x assembler-with-cpp -DNDEBUG -DSTM32F407xx -DUSE_HAL_DRIVER -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DSTM21F40XX -DUSE_USB_OTG_FS -DSTM32F40XX -I"D:/Users/muhammett/Desktop/TEZ\ECLIPSE/WORK_DISCO/CMM/include" -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


