#ifndef __ADC_H
#define __ADC_H	
#include "stm32f10x.h"
#include "stm32f10x_adc.h"
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//Mini STM32������
//ADC ��������			   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2010/6/7 
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ����ԭ�� 2009-2019
//All rights reserved					   
//////////////////////////////////////////////////////////////////////////////////	 

/*
#define ADC_CH0  0 //ͨ��0
#define ADC_CH1  1 //ͨ��1
#define ADC_CH2  2 //ͨ��2
#define ADC_CH3  3 //ͨ��3	   
*/
 #define INPUT1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)
 #define INPUT2 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_8)

void Adc_Init(void);
u16  Get_Adc1(u8 ch);  
u16 Get_Adc2(u8 ch); 
u16 Get_Adc1_28(u8 ch);   
u16 Get_Adc2_28(u8 ch);   
u16 Get_Adc1_Average(u8 ,u8 );
u16 Get_Adc2_Average(u8 ,u8 );

void deinit(void);
#endif 

