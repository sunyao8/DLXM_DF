 #include "task.h"
 #include "math.h"

u8 bf_c(u16 max)
{
if (((Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_2))>=max*995/1000))return 1;
else return 0;
}

u8 bg_c(u16 max)
{	
if (((Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_2))<=-(max*995/1000)))return 1;
else return 0;
}

u8 bfg_c(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_2))>=max*995/1000))return 1;
	else return 0;
	}

u8 bf_a(u16 max)
{
if (((Get_Adc1(ADC_Channel_10)-Get_Adc2(ADC_Channel_1))>=max*995/1000))return 1;
else return 0;
}

u8 bg_a(u16 max)
{	
if (((Get_Adc1(ADC_Channel_10)-Get_Adc2(ADC_Channel_1))<=-(max*995/1000)))return 1;
else return 0;
}

u8 bfg_a(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_10)-Get_Adc2(ADC_Channel_1))>=max*995/1000))return 1;
	else return 0;
	}


 /**************************************************************************/

 u8 bf_c1(u16 max)
{
if (((Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_15))>=max*995/1000))return 1;
else return 0;
}

u8 bg_c1(u16 max)
{	
if (((Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_15))<=-(max*995/1000)))return 1;
else return 0;
}

u8 bfg_c1(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_15))>=max*995/1000))return 1;
	else return 0;
	}

u8 bf_a1(u16 max)
{
if (((Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_4))>=max*995/1000))return 1;
else return 0;
}

u8 bg_a1(u16 max)
{	
if (((Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_4))<=-(max*995/1000)))return 1;
else return 0;
}

u8 bfg_a1(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_4))>=max*995/1000))return 1;
	else return 0;
}