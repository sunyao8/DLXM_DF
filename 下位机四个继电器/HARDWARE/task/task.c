 #include "task.h"
#include "math.h"
#include "stm32f10x_tim.h"

u8 C_flag=0,A_flag=0;
u32 C_count=0,A_count=0;

u8 bf_c(s32 max)
{s32 j=0;
j=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));
if ((j>max*990/1000))return 1;
else return 0;
}

u8 bg_c(u16 max)
{	
if (((Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8))<=-(max*0.995)))return 1;
else return 0;
}

u8 bfg_c(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8))>=max*995/1000))return 1;
	else return 0;
	}

u8 bf_a(s32 max)
{s32 j=0;
  j=(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8));
if ((j>max*990/1000))return 1;
else return 0;
}

u8 bg_a(u16 max)
{	
if (((Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8))<=-(max*0.995)))return 1;
else return 0;
}

u8 bfg_a(u16 max)
{
	if((abs(Get_Adc1(ADC_Channel_8)-Get_Adc2(ADC_Channel_1))>=max*995/1000))return 1;
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

void TIM3_Int_Init(u16 arr,u16 psc)
{	
    TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //ʱ��ʹ��
	
	//��ʱ��TIM4��ʼ��
	TIM_TimeBaseStructure.TIM_Period = arr; //��������һ�������¼�װ�����Զ���װ�ؼĴ������ڵ�ֵ	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //����������ΪTIMxʱ��Ƶ�ʳ�����Ԥ��Ƶֵ
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //����ʱ�ӷָ�:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM���ϼ���ģʽ
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //����ָ���Ĳ�����ʼ��TIMx��ʱ�������λ
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //ʹ��ָ����TIM4�ж�,��������ж�

	//�ж����ȼ�NVIC����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM4�ж�
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //��ռ���ȼ�0��
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;  //�����ȼ�3��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQͨ����ʹ��
	NVIC_Init(&NVIC_InitStructure);  //��ʼ��NVIC�Ĵ���


	TIM_Cmd(TIM3, ENABLE);  //ʹ��TIMx					 

}



void TIM3_IRQHandler(void)
{
if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM4�����жϷ������
		{	  
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );  //���TIMx�����жϱ�־
            if(C_flag==1)C_count++;
			if(A_flag==1)A_count++;
             }
}


s8 distin_A_C(void)
{
 u32 a_v=0,c_v=0,i;
    u32 max_av=0,max_cv=0;   

{	 for(i=0;i<1000;i++)
        {
	     a_v=Get_Adc1(ADC_Channel_1);	
		 c_v=Get_Adc2(ADC_Channel_4);
		 if(a_v>max_av)max_av=a_v;
		  if(c_v>max_cv)max_cv=c_v;
       }
	 for(i=0;i<700;i++)
        {
	     a_v=Get_Adc1(ADC_Channel_1);	
		 c_v=Get_Adc2(ADC_Channel_4);
		 if(a_v>(max_av*90/100))A_flag=1;
		 if(c_v>(max_cv*90/100))C_flag=1;
		 if(A_flag==1&&C_flag==1)break;
       }
	 	A_flag=0;
		C_flag=0;

	  
	  if(A_count>0)
	  	{  
        A_count=A_count*2/10;
if(A_count<=9&&A_count>=1)//5 6
	{	  A_count=0;
               C_count=0;
		  return 1;
      }

if(A_count<=20&&A_count>=11)//7 8
{	  A_count=0;
               C_count=0;
		  return 0;
      }

	  	}

/*********************************/
if(C_count>0)
      	{
      	C_count=C_count*2/10;
if(C_count<=9&&C_count>=1)//7 8
{
A_count=0;
C_count=0;
return 0;
}

if(C_count<=20&&C_count>=11)//5 6
{
A_count=0;
C_count=0;
return 1;
}


	  }


return 2;

 }


}




