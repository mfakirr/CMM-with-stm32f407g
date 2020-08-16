################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c \
E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c \
E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c 

OBJS += \
./src_USBD/usbd_core.o \
./src_USBD/usbd_ioreq.o \
./src_USBD/usbd_req.o 

C_DEPS += \
./src_USBD/usbd_core.d \
./src_USBD/usbd_ioreq.d \
./src_USBD/usbd_req.d 


# Each subdirectory must supply rules for building sources it contributes
src_USBD/usbd_core.o: E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_core.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"E:\MC\FLASH\ECLIPSE\WORK_DISCO\CMM\include" -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src_USBD/usbd_ioreq.o: E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_ioreq.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"E:\MC\FLASH\ECLIPSE\WORK_DISCO\CMM\include" -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src_USBD/usbd_req.o: E:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/src/usbd_req.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -Wextra  -g -DHSE_VALUE=8000000 -DUSE_STDPERIPH_DRIVER -DUSE_STM32F4_DISCOVERY -DUSE_USB_OTG_FS -DSTM32F40XX -I"E:\MC\FLASH\ECLIPSE\WORK_DISCO\CMM\include" -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/CMSIS/ST/STM32F4xx/Include/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Class/cdc/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_Device_Library/Core/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32_USB_OTG_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Libraries/STM32F4xx_StdPeriph_Driver/inc/ -IE:/MC/FLASH/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/ -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


