#include "timer.h"

void timer2_register(void){
	RCC->APB1ENR |=0x01;
	TIM2->ARR |= 0xffff;
	TIM2->PSC = 72-1;
	TIM2->CR1 |=0x1;
	TIM2->EGR |=0x1;
}

void timer3_register(void){
	RCC->APB1ENR |=(0x1<<1);
	
	TIM_TimeBaseInitTypeDef timer_Init;
	timer_Init.TIM_CounterMode = TIM_CounterMode_Up;
	timer_Init.TIM_Period = 0XFFFF;
	timer_Init.TIM_Prescaler = 72-1;
	TIM_TimeBaseInit(TIM3,&timer_Init);
	TIM_Cmd(TIM3, ENABLE);
	
	
}
void delay_ms_TIM2(uint16_t count){
	while(count){
		TIM2->CNT =0u;
		while ((TIM2->CNT)<1000){};
		count--;
	}
}