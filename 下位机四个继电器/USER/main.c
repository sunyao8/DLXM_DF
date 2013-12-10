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
 /////////////////////////UCOSII»ŒŒÒ∂—’ª…Ë÷√///////////////////////////////////
//START »ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define START_TASK_PRIO      			20 //ø™ º»ŒŒÒµƒ”≈œ»º∂…Ë÷√Œ™◊ÓµÕ
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define START_STK_SIZE  				64
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK START_TASK_STK[START_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
void start_task(void *pdata);	
 			   
//SWITCH2OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S1OPEN_TASK_PRIO       			5 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S1OPEN_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S1OPEN_TASK_STK[S1OPEN_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2open_task(void *pdata);
	void sa(void *pdata);
//SWITCH1OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S1CLOSE_TASK_PRIO       			6 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S1CLOSE_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2close_task(void *pdata);
	  void sb(void *pdata);;


//SWITCH2OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S2OPEN_TASK_PRIO       			7
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S2OPEN_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S2OPEN_TASK_STK[S2OPEN_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2open_task(void *pdata);
	void sc(void *pdata);
//SWITCH1OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S2CLOSE_TASK_PRIO       			8 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S2CLOSE_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2close_task(void *pdata);
	  void sd(void *pdata);
/***************************************************************/

//SWITCH2OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S3OPEN_TASK_PRIO       			9 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S3OPEN_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S3OPEN_TASK_STK[S3OPEN_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2open_task(void *pdata);
	void sa1(void *pdata);
//SWITCH1OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S3CLOSE_TASK_PRIO       			10 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S3CLOSE_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2close_task(void *pdata);
	  void sb1(void *pdata);;


//SWITCH2OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S4OPEN_TASK_PRIO       			11
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S4OPEN_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S4OPEN_TASK_STK[S4OPEN_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2open_task(void *pdata);
	void sc1(void *pdata);
//SWITCH1OPEN»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define S4CLOSE_TASK_PRIO       			12 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define S4CLOSE_STK_SIZE  		    		128
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
//void switch2close_task(void *pdata);
void sd1(void *pdata);

/**************************************************************/
//∞¥º¸…®√Ë»ŒŒÒ
//…Ë÷√»ŒŒÒ”≈œ»º∂
#define KEY_TASK_PRIO       			1 
//…Ë÷√»ŒŒÒ∂—’ª¥Û–°
#define KEY_STK_SIZE  					2560
//¥¥Ω®»ŒŒÒ∂—’ªø’º‰	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//»ŒŒÒ∫Ø ˝Ω”ø⁄
void key_task(void *pdata);			  
//////////////////////////////////////////////////////////////////////////////
//OS_EVENT * msg_key;			//∞¥º¸” œ‰ ¬º˛øÈ÷∏’Î
OS_EVENT * sem1_switch1open;		//∑–≈∫≈¡ø÷∏’Î	 	   
OS_EVENT * sem1_switch1close;	
OS_EVENT * sem1_switch2open;	 //∑–≈∫≈¡ø÷∏’Î			
OS_EVENT * sem1_switch2close; 
OS_EVENT * sem2_switch1open;	 //∑–≈∫≈¡ø÷∏’Î			
OS_EVENT * sem2_switch1close;	 
OS_EVENT * sem2_switch2open;  //∑–≈∫≈¡ø÷∏’Î 		 
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
    delay_init();	    	 //—” ±∫Ø ˝≥ı ºªØ	  
	NVIC_Configuration(); 	 //…Ë÷√NVIC÷–∂œ∑÷◊È2:2Œª«¿’º”≈œ»º∂£¨2ŒªœÏ”¶
	Adc_Init();
	deinit();
	 TIM3_Int_Init(200-1,72-1);	//“‘1Mhzµƒ∆µ¬ º∆ ˝
	OSInit();  	 			//≥ı ºªØUCOSII		 			  
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//¥¥Ω®∆ º»ŒŒÒ
	OSStart();	    
}

//ø™ º»ŒŒÒ
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
	pdata = pdata;
	
	sem1_switch1open=OSSemCreate(0);		//¥¥Ω®–≈∫≈¡ø
	sem1_switch1close=OSSemCreate(0);
	sem1_switch2open=OSSemCreate(0);		//¥¥Ω®–≈∫≈¡ø
	sem1_switch2close=OSSemCreate(0);
	sem2_switch1open=OSSemCreate(0);		//¥¥Ω®–≈∫≈¡ø
	sem2_switch1close=OSSemCreate(0);
	sem2_switch2open=OSSemCreate(0);		//¥¥Ω®–≈∫≈¡ø
	sem2_switch2close=OSSemCreate(0);
	
	OSStatInit();					//≥ı ºªØÕ≥º∆»ŒŒÒ.’‚¿Ôª·—” ±1√Î÷”◊Û”“	
 	OS_ENTER_CRITICAL();			//Ω¯»Î¡ŸΩÁ«¯(Œﬁ∑®±ª÷–∂œ¥Ú∂œ)    				    				   
    OSTaskCreate(sa,(void *)0,(OS_STK*)&S1OPEN_TASK_STK[S1OPEN_STK_SIZE-1],S1OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb,(void *)0,(OS_STK*)&S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE-1],S1CLOSE_TASK_PRIO); 
	OSTaskCreate(sc,(void *)0,(OS_STK*)&S2OPEN_TASK_STK[S2OPEN_STK_SIZE-1],S2OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd,(void *)0,(OS_STK*)&S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE-1],S2CLOSE_TASK_PRIO);
	OSTaskCreate(sa1,(void *)0,(OS_STK*)&S3OPEN_TASK_STK[S3OPEN_STK_SIZE-1],S3OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb1,(void *)0,(OS_STK*)&S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE-1],S3CLOSE_TASK_PRIO); 
	OSTaskCreate(sc1,(void *)0,(OS_STK*)&S4OPEN_TASK_STK[S4OPEN_STK_SIZE-1],S4OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd1,(void *)0,(OS_STK*)&S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE-1],S4CLOSE_TASK_PRIO);  
	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				   
 		
	OSTaskSuspend(START_TASK_PRIO);	//π“∆∆ º»ŒŒÒ.
	OS_EXIT_CRITICAL();				//ÕÀ≥ˆ¡ŸΩÁ«¯(ø…“‘±ª÷–∂œ¥Ú∂œ)
}	  
//A1 A*1ø™πÿ»ŒŒÒ ∑Â÷µ«– “ª∫≈µÁ»› ºÃµÁ∆˜1 
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
		     delay_us(17200);//15300		   60a=17000
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			delay_us(5200);//6667
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
		     delay_us(17200);//15300
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			delay_us(5200);//6667
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

    if(key2==1&&key1==1)break;
       	}	     	
              max=0;	 
	}
	
	}
	} //end


//A1 * B1µ “ª∫≈µÁ»›∆˜ ºÃµÁ∆˜1 π˝¡„Õ∂ 
	void sd(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
/*******************************************************/
if(flag_phase==1)

{
	  if(key1==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));						        
		    if((b>0)&&(b<=10))
			  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));				   
		           if((b>0)&&(b<=10))
				   {
					delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///º‰∏Ù ±º‰
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			 key1=0;
			 break;
			 }
		   }
   		  }
   }
		}
if(flag_phase==0)
{
	if(key2==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        
		   if((b>0)&&(b<=10))
		{	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        
		   if((b>0)&&(b<=10))
		  // if(b==0)
		   {					   
		      
				 delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  //PC11->0
			 ///  delay_us(7000);
			///delay_us(20000);	 ///º‰∏Ù ±º‰
			 delay_ms(100);//¬ˆ≥Â—” ±
			//   delay_us(100000);
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
	  
/*******************************************************/

   }
   }


//“ª∫≈µÁ»› 2∫≈ºÃµÁ∆˜ ∑Â÷µ«–
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
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
		 
		  for(i=1;i<512*2;i++)		 //600
		 if(bf_c(max))
		 	{ 	 
		     delay_us(17200);//15300
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			delay_us(5200);//6667
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

if(flag_phase==0)
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
		     delay_us(17200);//15300		   60a=17000
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			delay_us(5200);//6667
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
/*******************************************************/
		 
		               max=0;	 
    if(key2==0&&key1==0)	{ reset_open1=1;}     		     	
	}
	
	}
	} //end


//“ª∫≈µÁ»›   2∫≈ ºÃµÁ∆˜  π˝¡„Õ∂
	void sb(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch2close,0,&err);
/*******************************************************/
if(flag_phase==1)
{
	if(key2==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        
		   if((b>0)&&(b<=10))
		{	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_5)-Get_Adc2_28(ADC_Channel_4));						        
		   if((b>0)&&(b<=10))
		  // if(b==0)
		   {					   
		      
				 delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  //PC11->0
			 ///  delay_us(7000);
			///delay_us(20000);	 ///º‰∏Ù ±º‰
			 delay_ms(100);//¬ˆ≥Â—” ±
			//   delay_us(100000);
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

if(flag_phase==0)
{
	  if(key1==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));						        
		    if((b>0)&&(b<=10))
			  
		   {	 delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_2)-Get_Adc2_28(ADC_Channel_1));				   
		           if((b>0)&&(b<=10))
				   {
					delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  
			///		delay_us(7000);
			///	delay_us(20000);	 ///º‰∏Ù ±º‰
			delay_ms(100); 
		//	delay_us(100000);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			 key1=0;
			 break;
			 }
		   }
   		  }
   }
		}
/*******************************************************/
	
   }
   }

 /************************************************************/
 //A1 A*1ø™πÿ»ŒŒÒ	 A1µ„”…Get_Adc1(ADC_Channel_13)£¨A*1”…Get_Adc2(ADC_Channel_10) π˝¡„Õ∂

//2∫≈µÁ»› 1∫≈ºÃµÁ∆˜ ∑Â÷µ«–
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
		     delay_us(17200);//15300	 13634		16966
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			delay_us(5200);//15500	  5001	  8333
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
		     delay_us(17200);
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			delay_us(5200);//15500
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
		 
    if(key3==0&&key4==0)break;		 
       	}	     	
              max=0;	 
	}
	
	}
	} //end


//2∫≈µÁ»› 1∫≈ºÃµÁ∆˜ π˝¡„Õ∂
	void sd1(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem2_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
/*******************************************************/
if(flag_phase==1)
	  {
	  if(key3==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));						        
		    if((b>0)&&(b<=10))
			  
		   {	delay_us(20000);				   
		       	b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));		 
					    if((b>0)&&(b<=10))
				{
				 delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_13); 
		 //PC11->0
			delay_ms(100); 
		
		 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		 // OSSemPost(key1open);
			//OSMutexPost(key2open);
			 key3=0;
			 break;
			 }
		   }
   		  }
   }
		}

if(flag_phase==0)
{
	if(key4==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));					        
		   if((b>0)&&(b<=10))
		{	delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));						        
		   if((b>0)&&(b<=10))
		
		   {					   
		         //Õ∂«–—” ±
				delay_us(14300);
			
			GPIO_ResetBits(GPIOB,GPIO_Pin_14); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  //PC11->0
			 			   	///	delay_us(20000);	 ///º‰∏Ù ±º‰
			 delay_ms(100);//¬ˆ≥Â—” ±
			
		 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			  key4=0;
			 break;
		   }
		   }
   		  }
   }
}	  
/*******************************************************/
	  
   }
   }
//2∫≈µÁ»› 2∫≈ºÃµÁ∆˜ ∑Â÷µ«–
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
	     a=(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
		 if(a>max&&a>0)
		 max=a;
		 }
	         for(i=1;i<512*2;i++)	//600 
		 if(bf_c(max))
		 	{ 	 
		     delay_us(17200);
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			delay_us(5200);//15500
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

				if(flag_phase==0)
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
		     delay_us(17200);//15300	 13634		16966
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
			delay_us(5200);//15500	  5001	  8333
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
   /*******************************************************/
    		     	
              max=0;
	if(key3==0&&key4==0){ reset_open4=1;}
	}
	
	}
	}



//2∫≈µÁ»› 2∫≈ºÃµÁ∆˜ π˝¡„Õ∂
	void sb1(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem2_switch2close,0,&err);
/*******************************************************/
if(flag_phase==1)
{
	if(key4==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));					        
		   if((b>0)&&(b<=10))
		{	delay_us(20000);
			  b=abs(Get_Adc1_28(ADC_Channel_4)-Get_Adc2_28(ADC_Channel_7));						        
		   if((b>0)&&(b<=10))
		
		   {					   
		         //Õ∂«–—” ±
				delay_us(14300);
			
			GPIO_ResetBits(GPIOB,GPIO_Pin_14); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  //PC11->0
			 			   	///	delay_us(20000);	 ///º‰∏Ù ±º‰
			 delay_ms(100);//¬ˆ≥Â—” ±
			
		 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			  key4=0;
			 break;
		   }
		   }
   		  }
   }
}
if(flag_phase==0)
{
	  if(key3==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));						        
		    if((b>0)&&(b<=10))
			  
		   {	delay_us(20000);				   
		       	b=abs(Get_Adc1_28(ADC_Channel_1)-Get_Adc2_28(ADC_Channel_6));		 
					    if((b>0)&&(b<=10))
				{
				 delay_us(14300);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_13); 
		 //PC11->0
			delay_ms(100); 
		
		 GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		 // OSSemPost(key1open);
			//OSMutexPost(key2open);
			 key3=0;
			 break;
			 }
		   }
   		  }
   }
		}
/*******************************************************/
	
   }
   }


 /************************************************************/

//º‡Ã˝…œŒªª˙»ŒŒÒ
void key_task(void *pdata)  
{		    						 


	while(1)
	{ 
			if(first==1)
           {

		  while(1)
		   	{
		  		   flag_phase=distin_A_C();//flag_phaseŒ™1 «’˝–Ú
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
			 }//∑¢ÀÕœ˚œ¢	 
			if(INPUT2||start_2==1)
			{ 
				
                   OSSemPost(sem2_switch2open);
				

			
			  start_2=0;
			 }//∑¢ÀÕœ˚œ¢
		if(!INPUT1)
			{ 	
                     {    delay_ms(200);
			OSSemPost(sem1_switch2close);
			OSSemPost(sem1_switch1close);
				}
		
			
			 }//∑¢ÀÕœ˚œ¢
		if(!INPUT2)
			{ 

				{
						   delay_ms(200);
		      OSSemPost(sem2_switch2close);
                      OSSemPost(sem2_switch1close);
				}
		
			
			 }//∑¢ÀÕœ˚œ¢
	//	if(reset_open2==1){OSSemPost(sem1_switch2open);reset_open2=0; }	 
		if(reset_open1==1){OSSemPost(sem1_switch2open);reset_open1=0;	}
		if(reset_open4==1){OSSemPost(sem2_switch2open);reset_open4=0;}
    //	if(reset_open3==1){OSSemPost(sem2_switch1open);reset_open3=0;}

		  delay_ms(500);
 	
	}
}

 

