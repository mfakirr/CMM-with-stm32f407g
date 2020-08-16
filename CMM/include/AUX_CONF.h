#ifndef AUX_CONF_H_
#define AUX_CONF_H_
/*****************************************************/
static void INT_Config(void){
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_Init(&NVIC_InitStruct);

//										ADC_ITConfig(ADC1,ADC_IT_EOC, AC);
	NVIC_EnableIRQ(TIM2_IRQn);			TIM_ITConfig(TIM2        ,TIM_IT_Update, AC);
	NVIC_EnableIRQ(DMA2_Stream0_IRQn);	DMA_ITConfig(DMA2_Stream0,DMA_IT_TC|DMA_IT_HT, ENABLE);

/*
	NVIC_InitStruct.NVIC_IRQChannel						= TIM1_BRK_TIM9_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 1;
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	NVIC_InitStruct.NVIC_IRQChannel						= DMA2_Stream0_IRQn ;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority	= 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority			= 2;
	NVIC_InitStruct.NVIC_IRQChannelCmd					= ENABLE;
	NVIC_Init(&NVIC_InitStruct);
*/
}
/*****************************************************/
static void DMA_Config(void){
	DMA_InitTypeDef DMA_InitStruct;
// ADC
	DMA_DeInit(DMA2_Stream0);
	DMA_InitStruct.DMA_Channel				= DMA_Channel_0;
	DMA_InitStruct.DMA_PeripheralBaseAddr	= ADC_CDR_ADDRESS;
	DMA_InitStruct.DMA_Memory0BaseAddr		= (uint32_t)&ADCTripleConvertedValue;
	DMA_InitStruct.DMA_DIR					= DMA_DIR_PeripheralToMemory;
	DMA_InitStruct.DMA_BufferSize			= 6;									// 6 KANAL ADC kullanılıyor
	DMA_InitStruct.DMA_PeripheralInc		= DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_MemoryInc			= DMA_MemoryInc_Enable;
	DMA_InitStruct.DMA_PeripheralDataSize 	= DMA_PeripheralDataSize_HalfWord;
	DMA_InitStruct.DMA_MemoryDataSize		= DMA_MemoryDataSize_HalfWord;
	DMA_InitStruct.DMA_Mode					= DMA_Mode_Circular;
	DMA_InitStruct.DMA_Priority				= DMA_Priority_High;
	DMA_InitStruct.DMA_FIFOMode				= DMA_FIFOMode_Disable;	//	DMA_FIFOMode_Enable;
	DMA_InitStruct.DMA_FIFOThreshold		= DMA_FIFOThreshold_HalfFull;
	DMA_InitStruct.DMA_MemoryBurst			= DMA_MemoryBurst_Single;
	DMA_InitStruct.DMA_PeripheralBurst		= DMA_PeripheralBurst_Single;
	DMA_Init(DMA2_Stream0, &DMA_InitStruct);
	DMA_Cmd (DMA2_Stream0, ENABLE);
}
/*****************************************************/
void GPIO_Config(void){
	GPIO_DeInit(GPIOA);
	GPIO_DeInit(GPIOB);
	GPIO_DeInit(GPIOC);
	GPIO_DeInit(GPIOD);
	GPIO_DeInit(GPIOE);
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd(	RCC_AHB1Periph_DMA2  |
							RCC_AHB1Periph_GPIOA |
							RCC_AHB1Periph_GPIOB |
							RCC_AHB1Periph_GPIOC |
							RCC_AHB1Periph_GPIOD |
							RCC_AHB1Periph_GPIOE , ENABLE);
	RCC_APB1PeriphClockCmd(	RCC_APB1Periph_DAC   |
							RCC_APB1Periph_TIM2  |
							RCC_APB1Periph_TIM6  , ENABLE);
	RCC_APB2PeriphClockCmd(	RCC_APB2Periph_ADC1  |
							RCC_APB2Periph_ADC2  |
							RCC_APB2Periph_ADC3  ,ENABLE);
	GPIO_StructInit(&GPIO_InitStruct);
// adc1-> A:0,1,2,3,4,5,6,7 B:0,1 C:0,1,2,3,4,5
// adc2-> A:0,1,2,3,4,5,6,7 B:0,1 C:0,1,2,3,4,5
// adc3-> A:0,1,2,3               C:0,1,2,3
// CHANNEL 0,1,2,3,10,11,12,13
	GPIO_InitStruct.GPIO_Mode	= GPIO_AN;
	GPIO_InitStruct.GPIO_PuPd	= GPIO_Pull_NO;
	GPIO_InitStruct.GPIO_Pin	= GPIO_Pin_0 |GPIO_Pin_1 | GPIO_Pin_3;				GPIO_Init(GPIOA, &GPIO_InitStruct);// ADC CH  0  1  3
	GPIO_InitStruct.GPIO_Pin	= GPIO_Pin_1 |GPIO_Pin_2 | GPIO_Pin_3;				GPIO_Init(GPIOC, &GPIO_InitStruct);// ADC CH 11 12 13

	GPIO_InitStruct.GPIO_Mode	= GPIO_OUT;
	GPIO_InitStruct.GPIO_PuPd	= GPIO_Pull_UP;
	GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin	= GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15; 	GPIO_Init(GPIOD, &GPIO_InitStruct);

	GPIO_InitStruct.GPIO_Mode	= GPIO_AF;
	GPIO_InitStruct.GPIO_Speed	= GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType	= GPIO_Type_PP;
	GPIO_InitStruct.GPIO_PuPd	= GPIO_Pull_NO;
}
/*****************************************************/
void TIM2_Config(void){
	TIM_TimeBaseInitTypeDef TIM2_TimeBaseStruct;
	TIM_TimeBaseStructInit(&TIM2_TimeBaseStruct);
//	TIM2_TimeBaseStruct.TIM_Period			= (84000000 / 200000) - 1; // 200 KHz, from 84 MHz TIM2CLK (ie APB1 = HCLK/4, TIM2CLK = HCLK/2)
	TIM2_TimeBaseStruct.TIM_Period			= (84000000 /  20000) - 1; //  20 KHz, from 84 MHz TIM2CLK (ie APB1 = HCLK/4, TIM2CLK = HCLK/2)
	TIM2_TimeBaseStruct.TIM_Prescaler		= 0;
	TIM2_TimeBaseStruct.TIM_ClockDivision 	= 0;
	TIM2_TimeBaseStruct.TIM_CounterMode		= TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM2_TimeBaseStruct);
	TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update); // ADC_ExternalTrigConv_T2_TRGO Select output trigger to trigger ADC
	TIM_Cmd(TIM2, ENABLE);
}
/*****************************************************/
static void ADC_Config(void){
	ADC_DeInit();
	ADC_CommonInitTypeDef	ADC_CommonInitStruct;
	ADC_InitTypeDef ADC_InitStruct;
	ADC_CommonInitStruct.ADC_Mode			 = ADC_TripleMode_RegSimult; // ADC_DualMode_RegSimult; ADC_TripleMode_RegSimult
	ADC_CommonInitStruct.ADC_Prescaler		 = ADC_Prescaler_Div4;	//	ADC_Prescaler_Div2
	ADC_CommonInitStruct.ADC_DMAAccessMode	 = ADC_DMAAccessMode_1;
	ADC_CommonInitStruct.ADC_TwoSamplingDelay= ADC_TwoSamplingDelay_5Cycles;
	ADC_CommonInit(&ADC_CommonInitStruct);
	/*********************************************/
	ADC_InitStruct.ADC_Resolution			= ADC_Resolution_12b;
	ADC_InitStruct.ADC_ScanConvMode			= ENABLE; // 3 Channels
	ADC_InitStruct.ADC_ContinuousConvMode	= ENABLE; // Conversions Triggered
	ADC_InitStruct.ADC_ExternalTrigConvEdge	= ADC_ExternalTrigConvEdge_Rising;	//	ADC_ExternalTrigConvEdge_Rising; ADC_ExternalTrigConvEdge_None
	ADC_InitStruct.ADC_ExternalTrigConv		= ADC_ExternalTrigConv_T2_TRGO;		//	ADC_ExternalTrigConv_T2_TRGO;	ADC_ExternalTrigConv_T1_CC1
	ADC_InitStruct.ADC_DataAlign			= ADC_DataAlign_Right;
	ADC_InitStruct.ADC_NbrOfConversion		= 2;



//	ADC_InitStruct.ADC_ExternalTrigConvEdge	= ADC_ExternalTrigConvEdge_None;
//	ADC_InitStruct.ADC_ExternalTrigConv		= ADC_ExternalTrigConv_T1_CC1;


	ADC_Init(ADC1, &ADC_InitStruct);
	ADC_InitStruct.ADC_ExternalTrigConvEdge = ADC_ExternalTrigConvEdge_None; //Master is ADC1
	ADC_Init(ADC2, &ADC_InitStruct);
	ADC_Init(ADC3, &ADC_InitStruct);

	ADC_RegularChannelConfig(ADC1, ADC_Channel_0,  1, ADC_SampleTime_28Cycles);
	ADC_RegularChannelConfig(ADC1, ADC_Channel_11, 2, ADC_SampleTime_28Cycles);

	ADC_RegularChannelConfig(ADC2, ADC_Channel_1,  1, ADC_SampleTime_28Cycles);
	ADC_RegularChannelConfig(ADC2, ADC_Channel_12, 2, ADC_SampleTime_28Cycles);

	ADC_RegularChannelConfig(ADC3, ADC_Channel_3,  1, ADC_SampleTime_28Cycles); // 3,15,28,56,84,112,144,480
	ADC_RegularChannelConfig(ADC3, ADC_Channel_13, 2, ADC_SampleTime_28Cycles);
	/*********************************************/
	ADC_MultiModeDMARequestAfterLastTransferCmd(ENABLE);
	ADC_DMACmd(ADC1, ENABLE);
	ADC_Cmd(ADC1, ENABLE);
	ADC_Cmd(ADC2, ENABLE);
	ADC_Cmd(ADC3, ENABLE);
	ADC_SoftwareStartConv(ADC1);
}


/*****************************************************/
static void USB_Config(void){
#ifdef USE_USB_OTG_HS
	USBD_Init(&USB_OTG_dev,USB_OTG_HS_CORE_ID,&USR_desc,&USBD_CDC_cb,&USR_cb);
#else
	USBD_Init(&USB_OTG_dev,USB_OTG_FS_CORE_ID,&USR_desc,&USBD_CDC_cb,&USR_cb);
#endif
}
/*****************************************************/
static void Delay(__IO uint32_t nCount){while(nCount--){}}
/*****************************************************/
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line){while (1){}}
#endif
/*****************************************************/
#endif /* AUX_CONF_H_ */
