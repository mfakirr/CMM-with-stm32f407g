################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_core.c \
/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_dcd.c \
/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_dcd_int.c 

OBJS += \
./src_USB_OTG1/usb_core.o \
./src_USB_OTG1/usb_dcd.o \
./src_USB_OTG1/usb_dcd_int.o 

C_DEPS += \
./src_USB_OTG1/usb_core.d \
./src_USB_OTG1/usb_dcd.d \
./src_USB_OTG1/usb_dcd_int.d 


# Each subdirectory must supply rules for building sources it contributes
src_USB_OTG1/usb_core.o: /root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"../include" -I/usr/lib64/qt/include -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src_USB_OTG1/usb_dcd.o: /root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_dcd.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"../include" -I/usr/lib64/qt/include -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src_USB_OTG1/usb_dcd_int.o: /root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/src/usb_dcd_int.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"../include" -I/usr/lib64/qt/include -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -I/root/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


