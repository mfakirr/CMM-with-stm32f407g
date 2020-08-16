#ifndef AUX_FONK_H_
#define AUX_FONK_H_
	/*****************************************************/
	static void init_global(void){
		FreqBase		= 168000000; // A03 7A00 2^9 3 5^6 7
		FreqTimer		= (uint32_t)(SystemCoreClock);    // 168 MHz
		PrescalerValue	= (uint32_t)(FreqTimer/FreqBase); // 1
		int i=0;
		for(i=0;i< 9;i++){ADCTripleConvertedValue[i]=2048;}
		for(i=0;i<64;i++){rBuffer [i]=wBuffer[i]=0;}
		R_BUFFER=(uint16_t *)rBuffer;
		W_BUFFER=(uint16_t *)wBuffer;
		R_BUFFER[0]=W_BUFFER[0]=0;
		R_BUFFER[1]=W_BUFFER[1]=0;
		R_BUFFER[2]=W_BUFFER[2]=0;
		R_BUFFER[3]=W_BUFFER[3]=0;
	}
	/*****************************************************/
	static void update_USB(void){
		ind_1++;
		ind_1 %= numORT;

		vA1-=A1[ind_1];
		vA2-=A2[ind_1];
		vA3-=A3[ind_1];
		vA4-=A4[ind_1];
		vA5-=A5[ind_1];
		vA6-=A6[ind_1];

		A1[ind_1]=ADCTripleConvertedValue[0];
		A2[ind_1]=ADCTripleConvertedValue[1];
		A3[ind_1]=ADCTripleConvertedValue[2];
		A4[ind_1]=ADCTripleConvertedValue[3];
		A5[ind_1]=ADCTripleConvertedValue[4];
		A6[ind_1]=ADCTripleConvertedValue[5];

		vA1+=A1[ind_1];
		vA2+=A2[ind_1];
		vA3+=A3[ind_1];
		vA4+=A4[ind_1];
		vA5+=A5[ind_1];
		vA6+=A6[ind_1];

//		W_BUFFER[0]=vA1/numORT;
//		W_BUFFER[1]=vA2/numORT;
//		W_BUFFER[2]=vA3/numORT;
//		W_BUFFER[3]=vA4/numORT;
//		W_BUFFER[4]=vA5/numORT;
//		W_BUFFER[5]=vA6/numORT;

		W_BUFFER[0]=vA1>>10;
		W_BUFFER[1]=vA2>>10;
		W_BUFFER[2]=vA3>>10;
		W_BUFFER[3]=vA4>>10;
		W_BUFFER[4]=vA5>>10;
		W_BUFFER[5]=vA6>>10;

		W_BUFFER[6]=0;
		W_BUFFER[7]++;
		W_BUFFER[8]++;
		W_BUFFER[9]=W_BUFFER[9]+10;
		if(W_BUFFER[7]>=4096){W_BUFFER[7]=0;}
		if(W_BUFFER[8]>=4096){W_BUFFER[8]=0;}
		if(W_BUFFER[9]>=4096){W_BUFFER[9]=0;}
	}
	/*****************************************************/
#endif
