#ifndef __TASK_H
#define __TASK_H	
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include "delay.h"
#include "adc.h"
#include "stm32_dsp.h"

 u8 bf_a(s32);
 u8 bg_a(u16);
 u8 bfg_a(u16);

  u8 bf_c(s32);
 u8 bg_c(u16);
 u8 bfg_c(u16);
/****************************/
  u8 bf_a1(u16);
 u8 bg_a1(u16);
 u8 bfg_a1(u16);

  u8 bf_c1(u16);
 u8 bg_c1(u16);
 u8 bfg_c1(u16);
u8 bf_gl1(s32 max);
u8 bf_gl2(s32 max);
u8 bf_gl3(s32 max);
u8 bf_gl4(s32 max);

 void TIM3_IRQHandler(void);
void TIM3_Int_Init(u16 arr,u16 psc);
s8 distin_A_C(void);


#endif 
