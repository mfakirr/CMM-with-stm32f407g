#include "usbd_usr.h"
#include "usbd_ioreq.h"
USBD_Usr_cb_TypeDef USR_cb =
{
  USBD_USR_Init,
  USBD_USR_DeviceReset,
  USBD_USR_DeviceConfigured,
  USBD_USR_DeviceSuspended,
  USBD_USR_DeviceResumed,
  USBD_USR_DeviceConnected,
  USBD_USR_DeviceDisconnected,
};
void USBD_USR_Init(void){if (SysTick_Config(SystemCoreClock / 24)){while (1);}}
void USBD_USR_DeviceReset(uint8_t speed ){
	switch (speed){
		case USB_OTG_SPEED_HIGH: break;
		case USB_OTG_SPEED_FULL: break;
		default:				 break;
	}
}
void USBD_USR_DeviceConfigured (void){}
void USBD_USR_DeviceConnected (void){}
void USBD_USR_DeviceDisconnected (void){}
void USBD_USR_DeviceSuspended(void){}
void USBD_USR_DeviceResumed(void){}
