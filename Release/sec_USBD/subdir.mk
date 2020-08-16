################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c \
D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c \
D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c 

OBJS += \
./sec_USBD/usbd_core.o \
./sec_USBD/usbd_ioreq.o \
./sec_USBD/usbd_req.o 

C_DEPS += \
./sec_USBD/usbd_core.d \
./sec_USBD/usbd_ioreq.d \
./sec_USBD/usbd_req.d 


# Each subdirectory must supply rules for building sources it contributes
sec_USBD/usbd_core.o: D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -ID:/Users/muhammett/Desktop/TEZ/ECLIPSE/WORK_DISCO/CMM/include -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sec_USBD/usbd_ioreq.o: D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -ID:/Users/muhammett/Desktop/TEZ/ECLIPSE/WORK_DISCO/CMM/include -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

sec_USBD/usbd_req.o: D:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -ID:/Users/muhammett/Desktop/TEZ/ECLIPSE/WORK_DISCO/CMM/include -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -ID:/Users/muhammett/Desktop/TEZ/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


