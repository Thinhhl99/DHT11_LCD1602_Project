#include "main.h"




void delay_ms_TIM2(uint16_t count);

int main(void) {
	uint16_t counter=0;
	uint8_t i=0;
	uint16_t u16Tim;
	uint8_t u8CheckSum =0;
	char buffer[16];
	uint8_t u8Buffer[5];
	GPIO_Config_Output();
	/******************************************************/
			GPIO_InitTypeDef gpio_Init;
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
			gpio_Init.GPIO_Mode = GPIO_Mode_Out_OD;
			gpio_Init.GPIO_Pin = GPIO_Pin_12;
			gpio_Init.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_Init(GPIOB, &gpio_Init);
			GPIO_SetBits(GPIOB, GPIO_Pin_12);
			//GPIO_ResetBits(GPIOB, GPIO_Pin_12);
	/***************************/
	timer2_register(); 					/* Initialize:  'Delay_ms' Function*/
	
	/**** Configure: Clock and GPIO ****/
	// Configure: GPIO cho LCD- 4bit  // Clear config: PA4-PA7
	// PA4-PA7 Output Mode, Push-Pull // PB0-PB1 Output Mode, Push-Pull
	LCD_GPIO_Config();
  LCD_Init();                      // Initialize LCD
  LCD_Command(0x80);               // Move pointer to  1st line header
		//LCD_String("Counter(1s): ");   // Display string to LCD
		//LCD_Command(0xc0);
		//LCD_String("Le Huu Thinh");
		LCD_String("Hello, I'm Thinh");
		LCD_SetCursor(2,0);
		LCD_String("Lap Trinh stm32");
    while (1) {
		/************************/
			GPIO_ResetBits(GPIOB, GPIO_Pin_12);
			delay_ms_TIM2(20);
			GPIO_SetBits(GPIOB, GPIO_Pin_12);
			
		 TIM_SetCounter(TIM2, 0);
			while (TIM_GetCounter(TIM2)<10){
				if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
					break;
				}
			}
			u16Tim = TIM_GetCounter(TIM2);
			if( u16Tim >= 10){
				//while(1){}
				continue;
			}
		
			// Cho 12pin xuong thap
			TIM_SetCounter(TIM2, 0);
			while (TIM_GetCounter(TIM2)<45){
				if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
					break;
				}
			}
			u16Tim = TIM_GetCounter(TIM2);
			if( (u16Tim >= 45)||(u16Tim <=5)){
				//while(1){}
				continue;
			}
			
			// Cho 12pin len cao
			TIM_SetCounter(TIM2, 0);
			while (TIM_GetCounter(TIM2)<90){
				if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
					break;
				}
			}
			u16Tim = TIM_GetCounter(TIM2);
			if( (u16Tim >= 90)||(u16Tim <=70)){
				//while(1){}
				continue;
			}
			// Cho 12pin xuong thap
			TIM_SetCounter(TIM2, 0);
			while (TIM_GetCounter(TIM2)<95){
				if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
					break;
				}
			}
			u16Tim = TIM_GetCounter(TIM2);
			if( (u16Tim >= 95)||(u16Tim <=75)){
				//while(1){}
				continue;
			}
/****************************************/
/****************************************/

			//Receive:byte 1
			for(i=0; i<8; ++i){
					// Cho 12pin len cao
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<65){
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 65)||(u16Tim <=45)){
					while(1){}
					//continue;
				}
				// Cho 12pin xuong thap
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<80){
					if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 80)||(u16Tim <=10)){
					while(1){}
					//continue;
				}
			
			u8Buffer[0]<<=1;
			if(u16Tim>45){
				/*nhan duoc bit 1*/
				u8Buffer[0] |=1;
			}else{
				/*nhan duoc bit 0*/
				u8Buffer[0] &=~ 1;
			}
		}	
			//Receive:byte 2
			for(i=0; i<8; ++i){
					// Cho 12pin len cao
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<65){
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 65)||(u16Tim <=45)){
					while(1){}
					//continue;
				}
				// Cho 12pin xuong thap
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<80){
					if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 80)||(u16Tim <=10)){
					while(1){}
					//continue;
				}
			
			u8Buffer[1]<<=1;
			if(u16Tim>45){
				/*nhan duoc bit 1*/
				u8Buffer[1] |=1;
			}else{
				/*nhan duoc bit 0*/
				u8Buffer[1] &=~ 1;
			}
		}
			//Receive:byte 3
			for(i=0; i<8; ++i){
					// Cho 12pin len cao
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<65){
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 65)||(u16Tim <=45)){
					while(1){}
					//continue;
				}
				// Cho 12pin xuong thap
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<80){
					if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 80)||(u16Tim <=10)){
					while(1){}
					//continue;
				}
			
			u8Buffer[2]<<=1;
			if(u16Tim>45){
				/*nhan duoc bit 1*/
				u8Buffer[2] |=1;
			}else{
				/*nhan duoc bit 0*/
				u8Buffer[2] &=~ 1;
			}
		}
			//Receive:byte 4
			for(i=0; i<8; ++i){
					// Cho 12pin len cao
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<65){
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 65)||(u16Tim <=45)){
					while(1){}
					//continue;
				}
				// Cho 12pin xuong thap
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<80){
					if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 80)||(u16Tim <=10)){
					while(1){}
					//continue;
				}
			
			u8Buffer[3]<<=1;
			if(u16Tim>45){
				/*nhan duoc bit 1*/
				u8Buffer[3] |=1;
			}else{
				/*nhan duoc bit 0*/
				u8Buffer[3] &=~ 1;
			}
		}
			//Receive:byte 5
			for(i=0; i<8; ++i){
					// Cho 12pin len cao
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<65){
					if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 65)||(u16Tim <=45)){
					while(1){}
					//continue;
				}
				// Cho 12pin xuong thap
				TIM_SetCounter(TIM2, 0);
				while (TIM_GetCounter(TIM2)<80){
					if(!GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_12)){
						break;
					}
				}
				u16Tim = TIM_GetCounter(TIM2);
				if( (u16Tim >= 80)||(u16Tim <=10)){
					while(1){}
					//continue;
				}
			
			u8Buffer[4]<<=1;
			if(u16Tim>45){
				/*nhan duoc bit 1*/
				u8Buffer[4] |=1;
			}else{
				/*nhan duoc bit 0*/
				u8Buffer[4] &=~ 1;
			}
	}		
			/*****CHECKSUM*****/
/*			for (i=0; i<4; i++){
				u8CheckSum = u8Buffer[i];
			}
			if(u8CheckSum != u8Buffer[4]){
				while(1){}
			}
			
		/*******************************************/	
			GPIOC->ODR ^= 1<<13;
			
		/*
			//LCD_Clear();
			if(counter%10 <5){
				LCD_Scroll(RIGHT_SCROLL);
			}else{
				LCD_Scroll(LEFT_SCROLL);
			}	
			
			/****************************/
			/******************************/
			if(counter <15){
				LCD_Clear();
				LCD_String("Hello, I'm Thinh");
				LCD_SetCursor(2,0);
				LCD_String("Lap Trinh stm32");
					while(counter <14){
						delay_ms_TIM2(250);
						if(counter<5){
						LCD_Scroll(RIGHT_SCROLL);
						}else{
						LCD_Scroll(LEFT_SCROLL);
						}	
						counter++;
						
				}
			}else{
				LCD_Clear();
				LCD_String("Nhiet do: ");
				sprintf(buffer, "%d", u8Buffer[2]);
				LCD_String(buffer);
				LCD_String(" 0C");
				LCD_SetCursor(2,1);
				LCD_String("Do am: ");
				sprintf(buffer, "%d", u8Buffer[0]);
				LCD_String(buffer);
				LCD_String(" %");
			}		
			/****************************/
		
			counter = (counter + 1) % 100;
			/************** DELAY_MS ****************/
			delay_ms_TIM2(500);
    }
}



void GPIO_Config_Output(void){
	RCC->APB2ENR |= 0x10;  		/*Bit 4 IOPCEN: I/O port C clock enable*/
	RCC->APB2ENR |= 0x1<<3; 	/* PORT B: ENABLE CLOCK*/
	/*Cleat bit set MODE, CNF of Port C*/ /*Pin 13- Output mode, max speed 50MHz-Push-Pull*/
	//GPIOC->CRH &=0XFF0FFFFF;	
	//GPIOC->CRH |=0X00300000;	
	GPIOC->CRH |= SET_CONTIGUOUS_BIT_AT_OFFSET_TO_VALUE(GPIOC->CRH,4,20,3);
	//GPIOB->CRH |= SET_CONTIGUOUS_BIT_AT_OFFSET_TO_VALUE(GPIOB->CRH,4,16,3)\
								| SET_CONTIGUOUS_BIT_AT_OFFSET_TO_VALUE(GPIOC->CRH,4,20,3)\
								| SET_CONTIGUOUS_BIT_AT_OFFSET_TO_VALUE(GPIOC->CRH,4,28,3);
}


