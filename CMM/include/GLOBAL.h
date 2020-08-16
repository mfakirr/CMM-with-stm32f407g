__IO uint16_t ADCTripleConvertedValue[9];
uint16_t AN0, AN1, AN2, AN3, AN4, AN5, AN6, AN7, AN8;
#define ADC_CCR_ADDRESS    ((uint32_t)0x40012304)
#define ADC_CDR_ADDRESS    ((uint32_t)0x40012308)


#define RESET			0
#define KAPAT			0
#define AC				1
#define LED_iGREEN		GPIO_Pin_9 //PA9
#define LED_iRED		GPIO_Pin_5 //PD5
#define LED_GREEN		GPIO_Pin_12 //PD12
#define LED_ORANGE		GPIO_Pin_13 //PD13
#define LED_RED			GPIO_Pin_14 //PD14
#define LED_BLUE		GPIO_Pin_15 //PD15
#define GPIO_IN 		0x00
#define GPIO_OUT		0x01
#define GPIO_AF			0x02
#define GPIO_AN			0x03
#define GPIO_Pull_NO	0x00
#define GPIO_Pull_UP	0x01
#define GPIO_Pull_DOWN	0x02
#define GPIO_Type_PP	0x00
#define GPIO_Type_OD	0x01
uint32_t FreqBase;
uint32_t FreqTimer;
uint16_t PrescalerValue;
uint16_t *R_BUFFER;
uint16_t *W_BUFFER;
uint8_t   rBuffer[64];
uint8_t   wBuffer[64];

#define numORT			1024
uint16_t ind_1=0;

uint16_t A1[numORT],A2[numORT],A3[numORT],A4[numORT],A5[numORT],A6[numORT];
uint32_t vA1,vA2,vA3,vA4,vA5,vA6;



