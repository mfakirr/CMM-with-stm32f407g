#include <stdio.h>
#include <stdlib.h>
#include "stm32f4xx_conf.h"
// /root/STM/STM32F4-Discovery_FW_V1.1.0/Utilities/STM32F4-Discovery/
#include "stm32f4_discovery.h"
#include "stm32f4xx_it.h"
#include "usbd_cdc_core.h"
#include "usbd_cdc.h"
#include "usbd_usr.h"
#include "usbd_desc.h"

extern uint16_t cdc_DataTx (uint8_t* Buf, uint32_t Len);
__ALIGN_BEGIN USB_OTG_CORE_HANDLE    USB_OTG_dev __ALIGN_END ;

#include "GLOBAL.h"
#include "AUX_FONK.h"
#include "AUX_CONF.h"
#include "KESME.h"
/*--------------------------------------------------------------------------------*/
uint16_t ADC_Read(void){
	ADC_SoftwareStartConv(ADC1);
	while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	return ADC_GetConversionValue(ADC1);
}
/*--------------------------------------------------------------------------------*/
int main(void){
	int i=0;
	for(i=1;i<100;i++){Delay(0xFFFF);}	init_global ();
	for(i=1;i<100;i++){Delay(0xFFFF);}	GPIO_Config ();	GPIO_SetBits  (GPIOD, LED_RED);
	for(i=1;i<100;i++){Delay(0xFFFF);}	DMA_Config  ();	GPIO_SetBits  (GPIOD, LED_ORANGE);
	for(i=1;i<100;i++){Delay(0xFFFF);}	TIM2_Config();	GPIO_SetBits  (GPIOD, LED_GREEN);
	for(i=1;i<100;i++){Delay(0xFFFF);}	USB_Config  ();	GPIO_ResetBits(GPIOD, LED_RED);
	for(i=1;i<100;i++){Delay(0xFFFF);}	ADC_Config  ();	GPIO_ResetBits(GPIOD, LED_BLUE);
	for(i=1;i<100;i++){Delay(0xFFFF);}	INT_Config  ();	GPIO_ResetBits(GPIOD, LED_ORANGE);
	while (1){
//		cdc_DataTx (wBuffer,sizeof (wBuffer));
	    GPIO_SetBits  (GPIOD, LED_ORANGE | LED_BLUE);	    for(i=1;i<3;i++){Delay(0xFFFF);}
	    GPIO_ResetBits(GPIOD, LED_ORANGE | LED_BLUE);	    for(i=1;i<3;i++){Delay(0xFFFF);}

	    GPIO_SetBits  (GPIOD, LED_GREEN | LED_RED);	    for(i=1;i<10;i++){Delay(0xFFFF);}
	    GPIO_ResetBits(GPIOD, LED_GREEN | LED_RED);	    for(i=1;i<10;i++){Delay(0xFFFF);}
	}
}
