
#include "led.h"
#include "beep.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "lcd.h"
#include "usart.h"	 
#include "24cxx.h"
#include "touch.h"
#include "includes.h" 	 
#include <math.h>
#include "adc.h"
 #include "task.h"

//ALIENTEKս��STM32������ʵ��54
//UCOSIIʵ��2-�ź��������� 
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾  
 
/////////////////////////UCOSII�����ջ����///////////////////////////////////
//START ����
//�����������ȼ�
#define START_TASK_PRIO      			20 //��ʼ��������ȼ�����Ϊ���
//���������ջ��С
#define START_STK_SIZE  				64
//���������ջ�ռ�	
OS_STK START_TASK_STK[START_STK_SIZE];
//�������ӿ�
void start_task(void *pdata);	
 			   
//SWITCH1OPEN����
//�����������ȼ�
#define S1OPEN_TASK_PRIO       			7 
//���������ջ��С
#define S1OPEN_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S1OPEN_TASK_STK[S1OPEN_STK_SIZE];
//�������ӿ�
void switch1open_task(void *pdata);

//SWITCH1OPEN����
//�����������ȼ�
#define S1CLOSE_TASK_PRIO       			8 
//���������ջ��С
#define S1CLOSE_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE];
//�������ӿ�
void switch1close_task(void *pdata);


//SWITCH2OPEN����
//�����������ȼ�
#define S2OPEN_TASK_PRIO       			5 
//���������ջ��С
#define S2OPEN_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S2OPEN_TASK_STK[S2OPEN_STK_SIZE];
//�������ӿ�
//void switch2open_task(void *pdata);
	void sa(void *pdata);
//SWITCH1OPEN����
//�����������ȼ�
#define S2CLOSE_TASK_PRIO       			6 
//���������ջ��С
#define S2CLOSE_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE];
//�������ӿ�
//void switch2close_task(void *pdata);
	  void sb(void *pdata);;


//SWITCH2OPEN����
//�����������ȼ�
#define S3OPEN_TASK_PRIO       			9
//���������ջ��С
#define S3OPEN_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S3OPEN_TASK_STK[S3OPEN_STK_SIZE];
//�������ӿ�
//void switch2open_task(void *pdata);
	void sc(void *pdata);
//SWITCH1OPEN����
//�����������ȼ�
#define S4CLOSE_TASK_PRIO       			10 
//���������ջ��С
#define S4CLOSE_STK_SIZE  		    		128
//���������ջ�ռ�	
OS_STK S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE];
//�������ӿ�
//void switch2close_task(void *pdata);
	  void sd(void *pdata);;



//����ɨ������
//�����������ȼ�
#define KEY_TASK_PRIO       			3 
//���������ջ��С
#define KEY_STK_SIZE  					64
//���������ջ�ռ�	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//�������ӿ�
void key_task(void *pdata);
//////////////////////////////////////////////////////////////////////////////
//OS_EVENT * msg_key;			//���������¼���ָ��
OS_EVENT * sem1_switch1open;		//��ź���ָ��	 	   
OS_EVENT * sem1_switch1close;	
OS_EVENT * sem1_switch2open;	 //��ź���ָ��			
OS_EVENT * sem1_switch2close; 
OS_EVENT * sem2_switch1open;	 //��ź���ָ��			
OS_EVENT * sem2_switch1close;	 
OS_EVENT * sem2_switch2open;  //��ź���ָ�� 		 
OS_EVENT * sem2_switch2close; 
OS_EVENT * key1open;		     
OS_EVENT * key1close;
OS_EVENT * key2open;
OS_EVENT * key2close;
 INT8U e;
u8 key1=1,key2=1;


 int main(void)
 {	 
    delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_Configuration(); 	 //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	//uart_init(9600);
	//LED_Init();		  		//��ʼ����LED���ӵ�Ӳ���ӿ�
	//KEY_Init();	            //������ʼ��
	Adc_Init();
	deinit();
	OSInit();  	 			//��ʼ��UCOSII		 			  
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//������ʼ����
	OSStart();	    
}

//��ʼ����
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
	pdata = pdata;
	
	//msg_key=OSMboxCreate((void*)0);	//������Ϣ����
	sem1_switch1open=OSSemCreate(0);		//�����ź���
	sem1_switch1close=OSSemCreate(0);
	sem1_switch2open=OSSemCreate(0);		//�����ź���
	sem1_switch2close=OSSemCreate(0);
	sem2_switch1open=OSSemCreate(0);		//�����ź���
	sem2_switch1close=OSSemCreate(0);
	sem2_switch2open=OSSemCreate(0);		//�����ź���
	sem2_switch2close=OSSemCreate(0);
	key1open=OSSemCreate(0);                  //���������ź���
	key1close=OSSemCreate(1);
	key2open=OSSemCreate(0);
	key2close=OSSemCreate(1);
	
	OSStatInit();					//��ʼ��ͳ������.�������ʱ1��������	
 	OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)    				    				   
    OSTaskCreate(sa,(void *)0,(OS_STK*)&S2OPEN_TASK_STK[S2OPEN_STK_SIZE-1],S2OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb,(void *)0,(OS_STK*)&S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE-1],S2CLOSE_TASK_PRIO); 
	OSTaskCreate(sc,(void *)0,(OS_STK*)&S3OPEN_TASK_STK[S3OPEN_STK_SIZE-1],S3OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd,(void *)0,(OS_STK*)&S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE-1],S4CLOSE_TASK_PRIO); 
	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				   
 	OSTaskSuspend(START_TASK_PRIO);	//������ʼ����.
	OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)
}	  
//A1 A*1��������	 A1����Get_Adc1(ADC_Channel_13)��A*1��Get_Adc2(ADC_Channel_10) ����Ͷ
void sc(void *pdata)
{    u8 err;
    u16 max=0,a,i,j;
	
	while(1)
	{
	   OSSemPend(sem1_switch1open,0,&err);
	//OSSemPend(key1open, 0, &err);
	 if(key1==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_10)-Get_Adc2(ADC_Channel_1));	
//		delay_us(10);
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {
	    		
		 if(bf_a(max))
		{ 	 // delay_ms(16);
				delay_us(17000);
			   //nodelay_ms(5);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			   delay_ms(100);
			 
         GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			  max=0;
			 //OSMutexPost(key2close);
		//	 OSSemPost(key1close);
			 key1=1;
			  break;
		}
         }
	if(key1==0){max=0; OSSemPost(sem1_switch1open);}
	}
	}
	} //end

	void sd(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
	  if(key1==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_10)-Get_Adc2(ADC_Channel_12));						        
		    if((b>=0)&&(b<=4))
			  //if(b==0)
		   {					   
		       // delay_ms(13); 
					delay_us(14000);
				// delay_us(700);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  //PC11->0
					delay_us(7000);
			delay_ms(100); 
		
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		 // OSSemPost(key1open);
			//OSMutexPost(key2open);
			 key1=0;
			 break;
		   }
   		  }
   }	  
   }
   }

void sa(void *pdata)
{    u8 err;
    u16 max=0,a,i,j;
	
	while(1)
	{
	   OSSemPend(sem1_switch2open,0,&err);
	// OSMutexPend(key2open, 0, &err);
//	OSSemPend(key2open, 0, &err);
    if(key2==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_2));	
//	    delay_us(10); 
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {	
		 if(bf_c(max))
		{ 	 // delay_ms(16);
		      delay_us(17000);  
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			   delay_ms(100);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			  max=0;
			  key2=1;
			 //OSMutexPost(key2close);
			// OSSemPost(key2close);	    
			  break;
		}
         }	
		 if(key2==0) {max=0;OSSemPost(sem1_switch2open);}
	 
	}
	}
	} //end

	void sb(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch2close,0,&err);
	//OSMutexPend(key2close, 0, &err);
	// OSSemPend(key2close, 0, &err);
	if(key2==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_7));						        
		   if((b>=0)&&(b<=4))
		{	 delay_us(20000);
			  b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_7));						        
		   if((b>=0)&&(b<=5))
		  // if(b==0)
		   {					   
		        // delay_ms(13);      //Ͷ����ʱ
				// delay_us(700);
			
				 delay_us(14000);

			GPIO_ResetBits(GPIOB,GPIO_Pin_7); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  //PC11->0
			   delay_us(7000);
			 delay_ms(100);//������ʱ
			
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_7);
             // OSSemPost(key2open);    
			//OSMutexPost(key2open);
			  key2=0;
			 break;
		   }
		   }
   		  }
   }	  
   }
   }



//������λ������
void key_task(void *pdata)  
{			    						 
	while(1)
	{ 
		if(!INPUT1)
			{ OSSemPost(sem1_switch1open);
              OSSemPost(sem1_switch2open);
			 }//������Ϣ
		if(INPUT1)
			{ OSSemPost(sem1_switch1close);
		      OSSemPost(sem1_switch2close);
			 }//������Ϣ
 		delay_ms(500);
 	
	}
}

 
