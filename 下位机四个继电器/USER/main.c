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
#include "math.h"
#include "adc.h"
 #include "task.h"
 /////////////////////////UCOSIIÈÎÎñ¶ÑÕ»ÉèÖÃ///////////////////////////////////
//START ÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define START_TASK_PRIO      			20 //¿ªÊ¼ÈÎÎñµÄÓÅÏÈ¼¶ÉèÖÃÎª×îµÍ
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define START_STK_SIZE  				64
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK START_TASK_STK[START_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
void start_task(void *pdata);	
 			   
//SWITCH2OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S1OPEN_TASK_PRIO       			5 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S1OPEN_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S1OPEN_TASK_STK[S1OPEN_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2open_task(void *pdata);
	void sa(void *pdata);
//SWITCH1OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S1CLOSE_TASK_PRIO       			6
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S1CLOSE_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2close_task(void *pdata);
	  void sb(void *pdata);;


//SWITCH2OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S2OPEN_TASK_PRIO       			7
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S2OPEN_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S2OPEN_TASK_STK[S2OPEN_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2open_task(void *pdata);
	void sc(void *pdata);
//SWITCH1OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S2CLOSE_TASK_PRIO       			8 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S2CLOSE_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2close_task(void *pdata);
	  void sd(void *pdata);
/***************************************************************/

//SWITCH2OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S3OPEN_TASK_PRIO       			9 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S3OPEN_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S3OPEN_TASK_STK[S3OPEN_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2open_task(void *pdata);
	void sa1(void *pdata);
;//SWITCH1OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S3CLOSE_TASK_PRIO       			12 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S3CLOSE_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2close_task(void *pdata);
#define SWITCH1_CLOSETIME 19300
#define SWITCH2_CLOSETIME 5067
#define SWITCH12_OPENTIME 13400

	  void sb1(void *pdata);


//SWITCH2OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S4OPEN_TASK_PRIO       			11
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S4OPEN_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S4OPEN_TASK_STK[S4OPEN_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2open_task(void *pdata);
	void sc1(void *pdata);
//SWITCH1OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S4CLOSE_TASK_PRIO       			10 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S4CLOSE_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2close_task(void *pdata);
void sd1(void *pdata);

/**************************************************************/
//°´¼üÉ¨ÃèÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define KEY_TASK_PRIO       			1 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define KEY_STK_SIZE  					2560
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
void key_task(void *pdata);			  
//////////////////////////////////////////////////////////////////////////////
//OS_EVENT * msg_key;			//°´¼üÓÊÏäÊÂ¼ş¿éÖ¸Õë
OS_EVENT * sem1_switch1open;		//·ĞÅºÅÁ¿Ö¸Õë	 	   
OS_EVENT * sem1_switch1close;	
OS_EVENT * sem1_switch2open;	 //·ĞÅºÅÁ¿Ö¸Õë			
OS_EVENT * sem1_switch2close; 
OS_EVENT * sem2_switch1open;	 //·ĞÅºÅÁ¿Ö¸Õë			
OS_EVENT * sem2_switch1close;	 
OS_EVENT * sem2_switch2open;  //·ĞÅºÅÁ¿Ö¸Õë 		 
OS_EVENT * sem2_switch2close; 
 INT8U e;
u8 key1=0,key2=0,key3=0,key4=0;
u8 start_1=1,start_2=1;
u8 reset_open1=0,reset_open2=0,reset_open3=0,reset_open4=0;
extern u8 C_flag,A_flag;
extern u32 C_count,A_count;
s8 flag_phase=1;
s8 first=1;
 int main(void)
 {	 
    delay_init();	    	 //ÑÓÊ±º¯Êı³õÊ¼»¯	  
	NVIC_Configuration(); 	 //ÉèÖÃNVICÖĞ¶Ï·Ö×é2:2Î»ÇÀÕ¼ÓÅÏÈ¼¶£¬2Î»ÏìÓ¦
	Adc_Init();
	deinit();
	 TIM3_Int_Init(200-1,72-1);	//ÒÔ1MhzµÄÆµÂÊ¼ÆÊı
	OSInit();  	 			//³õÊ¼»¯UCOSII		 			  
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//´´½¨ÆğÊ¼ÈÎÎñ
	OSStart();	    
}

//¿ªÊ¼ÈÎÎñ
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
	pdata = pdata;
	
	sem1_switch1open=OSSemCreate(0);		//´´½¨ĞÅºÅÁ¿
	sem1_switch1close=OSSemCreate(0);
	sem1_switch2open=OSSemCreate(0);		//´´½¨ĞÅºÅÁ¿
	sem1_switch2close=OSSemCreate(0);
	sem2_switch1open=OSSemCreate(0);		//´´½¨ĞÅºÅÁ¿
	sem2_switch1close=OSSemCreate(0);
	sem2_switch2open=OSSemCreate(0);		//´´½¨ĞÅºÅÁ¿
	sem2_switch2close=OSSemCreate(0);
	
	OSStatInit();					//³õÊ¼»¯Í³¼ÆÈÎÎñ.ÕâÀï»áÑÓÊ±1ÃëÖÓ×óÓÒ	
 	OS_ENTER_CRITICAL();			//½øÈëÁÙ½çÇø(ÎŞ·¨±»ÖĞ¶Ï´ò¶Ï)    				    				   
    OSTaskCreate(sa,(void *)0,(OS_STK*)&S1OPEN_TASK_STK[S1OPEN_STK_SIZE-1],S1OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb,(void *)0,(OS_STK*)&S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE-1],S1CLOSE_TASK_PRIO); //8
//	OSTaskCreate(sc,(void *)0,(OS_STK*)&S2OPEN_TASK_STK[S2OPEN_STK_SIZE-1],S2OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd,(void *)0,(OS_STK*)&S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE-1],S2CLOSE_TASK_PRIO);//6
	OSTaskCreate(sa1,(void *)0,(OS_STK*)&S3OPEN_TASK_STK[S3OPEN_STK_SIZE-1],S3OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb1,(void *)0,(OS_STK*)&S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE-1],S3CLOSE_TASK_PRIO); 
//	OSTaskCreate(sc1,(void *)0,(OS_STK*)&S4OPEN_TASK_STK[S4OPEN_STK_SIZE-1],S4OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd1,(void *)0,(OS_STK*)&S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE-1],S4CLOSE_TASK_PRIO);  
	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				   
 		
	OSTaskSuspend(START_TASK_PRIO);	//¹ÒÆğÆğÊ¼ÈÎÎñ.
	OS_EXIT_CRITICAL();				//ÍË³öÁÙ½çÇø(¿ÉÒÔ±»ÖĞ¶Ï´ò¶Ï)
}	  
//A1 A*1¿ª¹ØÈÎÎñ ·åÖµÇĞ Ò»ºÅµçÈİ ¼ÌµçÆ÷1 
void sc(void *pdata)
{    u8 err;
   // u16 max=0,a=0;
	u16 i;
	    s32 max=0,a=0;

	while(1)
	{
	   OSSemPend(sem1_switch2open,0,&err);
    if(key2==0&&key1==0)
	{	
      while(1)
        {	
/*******************************************************/

if(flag_phase==1)
{
		 for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_a(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300		   60a=17000
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			delay_us(SWITCH2_CLOSETIME);//6667
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);

			  max=0;
			  key2=1;
			  key1=1;
			  break;
		}
}

if(flag_phase==0)
{
		 for(i=1;i<512*2;i++)				 //600
        {
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
		 
		  for(i=1;i<512*2;i++)		 //600
		 if(bf_c(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			delay_us(SWITCH2_CLOSETIME);//6667
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);

			  max=0;
			  key2=1;
			  key1=1;
			  break;
		}
    	}
/*******************************************************/
              max=0;	 
    if(key2==1&&key1==1)break;
       	}	     	
              max=0;	 
	}
	
	}
	} //end


//A1 * B1µ Ò»ºÅµçÈİÆ÷ ¼ÌµçÆ÷1 ¹ıÁãÍ¶ 
	void sd(void *pdata)
	{   u16 b;
	    u8 err,flag=0;
	u32 i;
	    s32 max=0,a=0;	
	while(1)
		{ OSSemPend(sem1_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
/*******************************************************/
if(flag_phase==1)

{
	  if(key1==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_2)-Get_Adc2(ADC_Channel_1));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl1(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			 key1=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
		}
if(flag_phase==0)
{
	if(key2==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_4));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl2(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); 
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			 key2=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
}
	  
/*******************************************************/

   }
   }


//Ò»ºÅµçÈİ 2ºÅ¼ÌµçÆ÷ ·åÖµÇĞ
void sa(void *pdata)
{    u8 err;
   // u16 max=0,a=0;
	u16 i;
	    s32 max=0,a=0;

	while(1)
	{
	   OSSemPend(sem1_switch2open,0,&err);
    if(key2==0&&key1==0)
	{	
/*******************************************************/
if(flag_phase==1)
{
		 for(i=1;i<512*2;i++)				 //600
        {
	     a=(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
		 
		  for(i=1;i<512*2;i++)		 //600
		 if(bf_c(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300
		     	GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);	
			delay_us(SWITCH2_CLOSETIME);//6667
			GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);

			  max=0;
			  key2=1;
			  key1=1;
			  break;
		}
    	}

if(flag_phase==0)
{
		 for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_a(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300		   60a=17000
	GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);		
			delay_us(SWITCH2_CLOSETIME);//6667
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);

			  max=0;
			  key2=1;
			  key1=1;
			  break;
		}
}
/*******************************************************/
		 
		               max=0;	 
    if(key2==0&&key1==0)	{ reset_open1=1;}     		     	
	}
	
	}
	} //end


//Ò»ºÅµçÈİ   2ºÅ ¼ÌµçÆ÷  ¹ıÁãÍ¶
	void sb(void *pdata)
	{   u16 b;
	    u8 err,flag=0;
	u32 i;
	    s32 max=0,a=0;	

	while(1)
		{ OSSemPend(sem1_switch2close,0,&err);
/*******************************************************/
if(flag_phase==1)
{
	if(key2==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_4));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl2(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); 
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			 key2=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
}

if(flag_phase==0)
{
	  if(key1==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_2)-Get_Adc2(ADC_Channel_1));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl1(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			 key1=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
		}
/*******************************************************/
	
   }
   }

 /************************************************************/
 //A1 A*1¿ª¹ØÈÎÎñ	 A1µãÓÉGet_Adc1(ADC_Channel_13)£¬A*1ÓÉGet_Adc2(ADC_Channel_10) ¹ıÁãÍ¶

//2ºÅµçÈİ 1ºÅ¼ÌµçÆ÷ ·åÖµÇĞ
void sc1(void *pdata)
{    u8 err;
   // u16 max=0,a=0;
	u16 i;
	    s32 max=0,a=0;

	while(1)
	{
	   OSSemPend(sem2_switch2open,0,&err);
    if(key3==0&&key4==0)
	{	
      while(1)
        {	
        /*******************************************************/
		if(flag_phase==1)
        	{
         for(i=1;i<512*2;i++)	   //850
        {
	     a=(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
         for(i=1;i<512*2;i++)	  //850
		 if(bf_a(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300	 13634		16966
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			delay_us(SWITCH2_CLOSETIME);//15500	  5001	  8333
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);

			  max=0;
			  key3=1;
			  key4=1;
			  break;
		}
        	}

		if(flag_phase==0)
		{
         for(i=1;i<512*2;i++)  //600
        {
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
	         for(i=1;i<512*2;i++)	//600 
		 if(bf_c(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			delay_us(SWITCH2_CLOSETIME);//15500
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);

			  max=0;
			  key3=1;
			  key4=1;
			  break;
		}
		}
/*******************************************************/
		              max=0;	  
    if(key3==0&&key4==0)break;		 
       	}	     	
              max=0;	 
	}
	
	}
	} //end


//2ºÅµçÈİ 1ºÅ¼ÌµçÆ÷ ¹ıÁãÍ¶
	void sd1(void *pdata)
	{   u16 b;
	    u8 err,flag=0;
	     u32 i;
	    s32 max=0,a=0;		
	while(1)
		{ OSSemPend(sem2_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
/*******************************************************/
if(flag_phase==1)
	  {
	  if(key3==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_7)-Get_Adc2(ADC_Channel_4));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl3(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_14); 
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			 key3=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
		}

if(flag_phase==0)
{
	if(key4==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_1));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl4(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
			GPIO_SetBits(GPIOB,GPIO_Pin_13);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			 key4=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
}	  
/*******************************************************/
	  
   }
   }
//2ºÅµçÈİ 2ºÅ¼ÌµçÆ÷ ·åÖµÇĞ
void sa1(void *pdata)
{    u8 err;
   // u16 max=0,a=0;
	u16 i;
	    s32 max=0,a=0;

	while(1)
	{
	   OSSemPend(sem2_switch2open,0,&err);
    if(key3==0&&key4==0)
	{
	/*******************************************************/
		if(flag_phase==1)
	{
         for(i=1;i<512*2;i++)  //600
        {
	     a=(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
	         for(i=1;i<512*2;i++)	//600 
		 if(bf_c(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);	 
			delay_us(SWITCH2_CLOSETIME);//15500
	GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);

			  max=0;
			  key3=1;
			  key4=1;
			  break;
		}
		}

				if(flag_phase==0)
        	{
         for(i=1;i<512*2;i++)	   //850
        {
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
         for(i=1;i<512*2;i++)	  //850
		 if(bf_a(max))
		 	{ 	 
		     delay_us(SWITCH1_CLOSETIME);//15300	 13634		16966
		 	GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);    		
			delay_us(SWITCH2_CLOSETIME);//15500	  5001	  8333
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			 //  delay_ms(100);
			   delay_us(100000);
         GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
		          GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);

			  max=0;
			  key3=1;
			  key4=1;
			  break;
		}
        	}
   /*******************************************************/
    		     	
              max=0;
	if(key3==0&&key4==0){ reset_open4=1;}
	}
	
	}
	}



//2ºÅµçÈİ 2ºÅ¼ÌµçÆ÷ ¹ıÁãÍ¶
	void sb1(void *pdata)
	{   u16 b;
	    u8 err,flag=0;
	     u32 i;
	    s32 max=0,a=0;
	while(1)
		{ OSSemPend(sem2_switch2close,0,&err);
/*******************************************************/
if(flag_phase==1)
{
	if(key4==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_1));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl4(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); 
			GPIO_SetBits(GPIOB,GPIO_Pin_13);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			 key4=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
}
if(flag_phase==0)
{
	  if(key3==1)
  {   		delay_us(20000);

  		 while(1)
        { 	flag=0;
                a=0;
		 max=0;
            for(i=1;i<512*2;i++)		   //850
        {
	     a=(Get_Adc1(ADC_Channel_7)-Get_Adc2(ADC_Channel_4));	 
		 if(a>max&&a>0)
		 max=a;

	 }
			
		 	 for(i=1;i<512*2;i++)		 //850
		            if(bf_gl3(max))
		            	{
			for(i=1;i<512*2;i++)		 //850			
				{
			b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));						        

			if((b>0)&&(b<=4))	  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));				   
		           if((b>0)&&(b<=4))
				   {
					delay_us(SWITCH12_OPENTIME);
			GPIO_ResetBits(GPIOB,GPIO_Pin_14); 
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///¼ä¸ôÊ±¼ä
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			 key3=0;
			 flag=1;
			 break;
			 }



			}

				}

		            	break;}

		 if(flag==1)break;}
   }
		}
/*******************************************************/
	
   }
   }


 /************************************************************/

//¼àÌıÉÏÎ»»úÈÎÎñ
void key_task(void *pdata)  
{		    						 


	while(1)
	{ 
			if(first==1)
           {

		  while(1)
		   	{
		  		   flag_phase=distin_A_C();//flag_phaseÎª1ÊÇÕıĞò
		   if(flag_phase!=2)break;
		   	}
		   
		/*   
                 if(flag_out_56==0)
               {
                OSTaskChangePrio(S1OPEN_TASK_PRIO,4);
                OSTaskChangePrio(S2OPEN_TASK_PRIO,3);
                OSTaskChangePrio(S3OPEN_TASK_PRIO,16);//14
                OSTaskChangePrio(S4OPEN_TASK_PRIO,15); //13

               OSTaskChangePrio(S1CLOSE_TASK_PRIO,18);
                OSTaskChangePrio(S2CLOSE_TASK_PRIO,17);
                OSTaskChangePrio(S3CLOSE_TASK_PRIO,14);
                OSTaskChangePrio(S4CLOSE_TASK_PRIO,13);
               }
		*/		
            first=0;
        }





		if(INPUT1||start_1==1)
			{
			
                     OSSemPost(sem1_switch2open);
				
				 start_1=0;
			 }//·¢ËÍÏûÏ¢	 
			if(INPUT2||start_2==1)
			{ 
				
                   OSSemPost(sem2_switch2open);
				

			
			  start_2=0;
			 }//·¢ËÍÏûÏ¢
		if(!INPUT1)
			{ 	
                     {    delay_ms(200);
			OSSemPost(sem1_switch2close);
			OSSemPost(sem1_switch1close);
				}
		
			
			 }//·¢ËÍÏûÏ¢
		if(!INPUT2)
			{ 

				{
						   delay_ms(200);
		      OSSemPost(sem2_switch2close);
                      OSSemPost(sem2_switch1close);
				}
		
			
			 }//·¢ËÍÏûÏ¢
	//	if(reset_open2==1){OSSemPost(sem1_switch2open);reset_open2=0; }	 
		if(reset_open1==1){OSSemPost(sem1_switch2open);reset_open1=0;	}
		if(reset_open4==1){OSSemPost(sem2_switch2open);reset_open4=0;}
    //	if(reset_open3==1){OSSemPost(sem2_switch1open);reset_open3=0;}

		  delay_ms(500);
 	
	}
}

 

