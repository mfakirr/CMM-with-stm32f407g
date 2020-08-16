#include "stm32f4xx_it.h"
#include "usb_core.h"
#include "usbd_core.h"
#include "stm32f4_discovery.h"
#include "usbd_cdc_core.h"

void NMI_Handler		(void){}
void HardFault_Handler	(void){  while (1)  {}}
void MemManage_Handler	(void){  while (1)  {}}
void BusFault_Handler	(void){  while (1)  {}}
void UsageFault_Handler	(void){  while (1)  {}}
void DebugMon_Handler	(void){}
void SVC_Handler		(void){}
void PendSV_Handler		(void){}
void SysTick_Handler	(void){}
/***********************************************************************/
extern USB_OTG_CORE_HANDLE           USB_OTG_dev;
extern uint32_t USBD_OTG_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
extern void DISCOVERY_EXTI_IRQHandler(void);
/***********************************************************************/
void EXTI0_IRQHandler(void){
	DISCOVERY_EXTI_IRQHandler();
	EXTI_ClearITPendingBit(USER_BUTTON_EXTI_LINE);
}
/***********************************************************************/
#ifdef USE_USB_OTG_FS
	void OTG_FS_WKUP_IRQHandler(void){
		if(USB_OTG_dev.cfg.low_power){
			*(uint32_t *)(0xE000ED10) &= 0xFFFFFFF9 ;
			SystemInit();
			USB_OTG_UngateClock(&USB_OTG_dev);
		}
		EXTI_ClearITPendingBit(EXTI_Line18);
	}
	void OTG_FS_IRQHandler(void){USBD_OTG_ISR_Handler (&USB_OTG_dev);}
#endif
#ifdef USE_USB_OTG_HS
	#ifdef USB_OTG_HS_DEDICATED_EP1_ENABLED
		extern uint32_t USBD_OTG_EP1IN_ISR_Handler (USB_OTG_CORE_HANDLE *pdev);
		extern uint32_t USBD_OTG_EP1OUT_ISR_Handler(USB_OTG_CORE_HANDLE *pdev);
		void OTG_HS_EP1_IN_IRQHandler (void){USBD_OTG_EP1IN_ISR_Handler (&USB_OTG_dev);}
		void OTG_HS_EP1_OUT_IRQHandler(void){USBD_OTG_EP1OUT_ISR_Handler(&USB_OTG_dev);}
	#endif
	void OTG_HS_WKUP_IRQHandler(void){
		if(USB_OTG_dev.cfg.low_power){
			*(uint32_t *)(0xE000ED10) &= 0xFFFFFFF9 ;
			SystemInit();
			USB_OTG_UngateClock(&USB_OTG_dev);
		}
		EXTI_ClearITPendingBit(EXTI_Line20);
	}
	void OTG_HS_IRQHandler(void){USBD_OTG_ISR_Handler (&USB_OTG_dev);}
#endif
/***********************************************************************/
