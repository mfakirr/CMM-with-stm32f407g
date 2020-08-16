/*--------------------------------------------------------------------------------*/
#ifndef __USB_CONF__H__
	#define __USB_CONF__H__
	#include "stm32f4xx.h"
//	#define USE_USB_OTG_HS
//	#define USE_USB_OTG_FS
//	#define USE_ULPI_PHY
//	#define USE_EMBEDDED_PHY
//	#define USE_HOST_MODE
//	#define USE_OTG_MODE
	#define USE_DEVICE_MODE

	#ifdef USE_USB_OTG_FS
		#define USB_OTG_FS_CORE
	#endif
	#ifdef USE_USB_OTG_HS
		#define USB_OTG_HS_CORE
	#endif
	#ifndef USE_I2C_PHY
		#define USE_I2C_PHY
	#endif

	#ifndef USB_OTG_FS_CORE
		#ifndef USB_OTG_HS_CORE
			#error  "USB_OTG_HS_CORE or USB_OTG_FS_CORE should be defined"
		#endif
	#endif
	#ifndef USE_DEVICE_MODE
		#ifndef USE_HOST_MODE
			#error  "USE_DEVICE_MODE or USE_HOST_MODE should be defined"
		#endif
	#endif
	#ifndef USE_USB_OTG_HS
		#ifndef USE_USB_OTG_FS
			#error  "USE_USB_OTG_HS or USE_USB_OTG_FS should be defined"
		 #endif
	#else
		#ifndef USE_ULPI_PHY
			#ifndef USE_EMBEDDED_PHY
				#ifndef USE_I2C_PHY
					#error  "USE_ULPI_PHY or USE_EMBEDDED_PHY or USE_I2C_PHY should be defined"
				#endif
			#endif
		#endif
	#endif
/******************************************************************************/
	#ifdef USB_OTG_HS_CORE
		#define  RX_FIFO_HS_SIZE                          512
		#define TX0_FIFO_HS_SIZE                          64
		#define TX1_FIFO_HS_SIZE                         384
		#define TX2_FIFO_HS_SIZE                          64
		#define TX3_FIFO_HS_SIZE                           0
		#define TX4_FIFO_HS_SIZE                           0
		#define TX5_FIFO_HS_SIZE                           0
 //		#define USB_OTG_HS_SOF_OUTPUT_ENABLED
		#ifdef USE_ULPI_PHY
			#define USB_OTG_ULPI_PHY_ENABLED
		#endif
		#ifdef USE_EMBEDDED_PHY
			#define USB_OTG_EMBEDDED_PHY_ENABLED/* wakeup is working only when HS core is configured in FS mode */
			#define USB_OTG_HS_LOW_PWR_MGMT_SUPPORT
		#endif
		#ifdef USE_I2C_PHY
			#define USB_OTG_I2C_PHY_ENABLED
		#endif
 /*		#define USB_OTG_HS_INTERNAL_DMA_ENABLED */ /* Be aware that enabling DMA mode will result in data being sent only by
                                                  multiple of 4 packet sizes. This is due to the fact that USB DMA does
                                                  not allow sending data from non word-aligned addresses.
                                                  For this specific application, it is advised to not enable this option
                                                  unless required. */
		#define USB_OTG_HS_DEDICATED_EP1_ENABLED
	#endif
/****************** USB OTG FS CONFIGURATION **********************************/
	#ifdef USB_OTG_FS_CORE
		#define  RX_FIFO_FS_SIZE            	128
		#define TX0_FIFO_FS_SIZE          		64
		#define TX1_FIFO_FS_SIZE             	128
		#define TX2_FIFO_FS_SIZE              	0
		#define TX3_FIFO_FS_SIZE            	0
//		#define USB_OTG_FS_LOW_PWR_MGMT_SUPPORT
//		#define USB_OTG_FS_SOF_OUTPUT_ENABLED
	#endif
/******************************************************************************/
	#ifdef USB_OTG_HS_INTERNAL_DMA_ENABLED
		#if defined   (__GNUC__)        /* GNU Compiler */
			#define __ALIGN_END    __attribute__ ((aligned (4)))
			#define __ALIGN_BEGIN
		#endif /* __GNUC__ */
	#else
		#define __ALIGN_BEGIN
		#define __ALIGN_END
	#endif /* USB_OTG_HS_INTERNAL_DMA_ENABLED */
	/* __packed keyword used to decrease the data type alignment to 1-byte */
	#define __packed    __attribute__ ((__packed__))
#endif //__USB_CONF__H__
