/*--------------------------------------------------------------------------------*/
#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
#pragma     data_alignment = 4
#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */

#include "usbd_cdc.h"
#include "stm32f4_discovery.h"

extern	uint8_t  rBuffer[64];
extern	uint8_t  wBuffer[64];

extern	uint8_t  APP_Rx_Buffer []; /* Write CDC received data in this buffer. These data will be sent over USB IN endpoint in the CDC core functions. */
extern	uint32_t APP_Rx_ptr_in;    /* Increment this pointer or roll it back to start address when writing received data in the buffer APP_Rx_Buffer. */

static	uint16_t cdc_Init     (void);
static	uint16_t cdc_DeInit   (void);
static	uint16_t cdc_Ctrl     (uint32_t Cmd, uint8_t* Buf, uint32_t Len);
		uint16_t cdc_DataTx   (uint8_t* Buf, uint32_t Len);
static	uint16_t cdc_DataRx   (uint8_t* Buf, uint32_t Len);
/*--------------------------------------------------------------------------------*/
CDC_IF_Prop_TypeDef cdc_fops ={
  cdc_Init,
  cdc_DeInit,
  cdc_Ctrl,
  cdc_DataTx,
  cdc_DataRx
};
/************************************************************************/
static uint16_t cdc_Init  (void){return USBD_OK;}
static uint16_t cdc_DeInit(void){return USBD_OK;}
/************************************************************************/
static uint16_t cdc_Ctrl (uint32_t Cmd, uint8_t* Buf, uint32_t Len){
  switch (Cmd) {
		case SEND_ENCAPSULATED_COMMAND:	/* Not  needed for this driver */	break;
		case GET_ENCAPSULATED_RESPONSE:	/* Not  needed for this driver */	break;
		case SET_COMM_FEATURE:			/* Not  needed for this driver */	break;
		case GET_COMM_FEATURE:			/* Not  needed for this driver */	break;
		case CLEAR_COMM_FEATURE:		/* Not  needed for this driver */	break;
		case SET_LINE_CODING:												break;
		case GET_LINE_CODING:												break;
		case SET_CONTROL_LINE_STATE:	/* Not  needed for this driver */	break;
		case SEND_BREAK:				/* Not  needed for this driver */	break;
		default:															break;
  }
  return USBD_OK;
}
/************************************************************************/
uint16_t cdc_DataTx (uint8_t* Buf, uint32_t Len){
	for(uint32_t i = 0; i < Len; i++ ){								//loop through buffer
		APP_Rx_Buffer[APP_Rx_ptr_in] = Buf[i] ;						//push data into transfer buffer
		APP_Rx_ptr_in++;											//increase pointer value
		if(APP_Rx_ptr_in == APP_RX_DATA_SIZE){APP_Rx_ptr_in = 0;}	//To avoid buffer overflow
	}
	return USBD_OK;
}
/************************************************************************/
static uint16_t cdc_DataRx (uint8_t* Buf, uint32_t Len){
	for (uint32_t i = 0; i < Len; i++){rBuffer[i]=*(Buf+i);}
	return USBD_OK;
}
/************************************************************************/
void DISCOVERY_EXTI_IRQHandler(void){								//this function is run when the user button is pushed
	cdc_DataTx (wBuffer,(uint32_t)sizeof (wBuffer));
}
/************************************************************************/
