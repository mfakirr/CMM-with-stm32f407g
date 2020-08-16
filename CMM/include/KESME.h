/***********************************************************************/
void DMA2_Stream0_IRQHandler(void){
//	static int i=0;
//	if(i==0){GPIO_ResetBits  (GPIOD, LED_RED); i=1;}
//	else{GPIO_SetBits  (GPIOD, LED_RED); i=0;}
	update_USB();
	cdc_DataTx (wBuffer,sizeof (wBuffer));

	if(DMA_GetITStatus(DMA2_Stream0, DMA_IT_HTIF0)){		/* Test on DMA Stream Half Transfer interrupt */
		DMA_ClearITPendingBit(DMA2_Stream0, DMA_IT_HTIF0);	/* Clear DMA Stream Half Transfer interrupt pending bit */
//		GPIO_SetBits  (GPIOD, LED_GREEN);
	}

	if(DMA_GetITStatus(DMA2_Stream0, DMA_IT_TCIF0)){		/* Test on DMA Stream Transfer Complete interrupt */
		DMA_ClearITPendingBit(DMA2_Stream0, DMA_IT_TCIF0);	/* Clear DMA Stream Transfer Complete interrupt pending bit */
//		GPIO_ResetBits  (GPIOD, LED_GREEN);

	}
//	DMA_ClearFlag(DMA2_Stream0, DMA_FLAG_TCIF0 | DMA_IT_TEIF0);
}
/***********************************************************************/
void TIM2_IRQHandler(void){if (TIM_GetITStatus(TIM2, TIM_IT_Update) != RESET){TIM_ClearITPendingBit(TIM2, TIM_IT_Update);}}
/***********************************************************************/
