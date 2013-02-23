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
//SWITCH1OPENÈÎÎñ
//ÉèÖÃÈÎÎñÓÅÏÈ¼¶
#define S3CLOSE_TASK_PRIO       			10 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define S3CLOSE_STK_SIZE  		    		128
//´´½¨ÈÎÎñ¶ÑÕ»¿Õ¼ä	
OS_STK S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE];
//ÈÎÎñº¯Êı½Ó¿Ú
//void switch2close_task(void *pdata);
	  void sb1(void *pdata);;


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
#define S4CLOSE_TASK_PRIO       			12 
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
#define KEY_TASK_PRIO       			3 
//ÉèÖÃÈÎÎñ¶ÑÕ»´óĞ¡
#define KEY_STK_SIZE  					64
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


 int main(void)
 {	 
    delay_init();	    	 //ÑÓÊ±º¯Êı³õÊ¼»¯	  
	NVIC_Configuration(); 	 //ÉèÖÃNVICÖĞ¶Ï·Ö×é2:2Î»ÇÀÕ¼ÓÅÏÈ¼¶£¬2Î»ÏìÓ¦
	Adc_Init();
	deinit();
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
 	OSTaskCreate(sb,(void *)0,(OS_STK*)&S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE-1],S1CLOSE_TASK_PRIO); 
	OSTaskCreate(sc,(void *)0,(OS_STK*)&S2OPEN_TASK_STK[S2OPEN_STK_SIZE-1],S2OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd,(void *)0,(OS_STK*)&S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE-1],S2CLOSE_TASK_PRIO);
	OSTaskCreate(sa1,(void *)0,(OS_STK*)&S3OPEN_TASK_STK[S3OPEN_STK_SIZE-1],S3OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb1,(void *)0,(OS_STK*)&S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE-1],S3CLOSE_TASK_PRIO); 
	OSTaskCreate(sc1,(void *)0,(OS_STK*)&S4OPEN_TASK_STK[S4OPEN_STK_SIZE-1],S4OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd1,(void *)0,(OS_STK*)&S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE-1],S4CLOSE_TASK_PRIO);  
	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				   
 		
	OSTaskSuspend(START_TASK_PRIO);	//¹ÒÆğÆğÊ¼ÈÎÎñ.
	OS_EXIT_CRITICAL();				//ÍË³öÁÙ½çÇø(¿ÉÒÔ±»ÖĞ¶Ï´ò¶Ï)
}	  
//A1 A*1¿ª¹ØÈÎÎñ	 A1µãÓÉGet_Adc1(ADC_Channel_13)£¬A*1ÓÉGet_Adc2(ADC_Channel_10) ¹ıÁãÍ¶
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
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {
	    		
		 if(bg_a(max))
		{ 	 
				delay_us(17000);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
			   delay_ms(100);
			 
         GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
			  max=0;
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
		    if((b>0)&&(b<=4))
			  //if(b==0)
		   {					   
		        
					delay_us(14000);
			GPIO_ResetBits(GPIOB,GPIO_Pin_5); 
			GPIO_SetBits(GPIOB,GPIO_Pin_6);  
					delay_us(7000);
			delay_ms(100); 
		
		 GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_5);
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
    if(key2==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_2));	 
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {	
		 if(bg_c(max))
		{ 	 
		     delay_us(17000);
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			   delay_ms(100);
         GPIO_ResetBits(GPIOB,GPIO_Pin_7);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_8);
			  max=0;
			  key2=1;	    
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
	if(key2==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_7));						        
		   if((b>0)&&(b<=4))
		{	 delay_us(20000);
			  b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_7));						        
		   if((b>0)&&(b<=5))
		  // if(b==0)
		   {					   
		      
				 delay_us(14000);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  //PC11->0
			   delay_us(7000);
			 delay_ms(100);//Âö³åÑÓÊ±
			
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

 /************************************************************/
 //A1 A*1¿ª¹ØÈÎÎñ	 A1µãÓÉGet_Adc1(ADC_Channel_13)£¬A*1ÓÉGet_Adc2(ADC_Channel_10) ¹ıÁãÍ¶
void sc1(void *pdata)
{    u8 err;
    u16 max=0,a,i,j;
	
	while(1)
	{
	   OSSemPend(sem2_switch1open,0,&err);
	//OSSemPend(key1open, 0, &err);
	 if(key3==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_4));	
//		delay_us(10);
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {
	    		
		if((abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_4)))>=max*800/1000)
		{ 	 // delay_ms(16);
				delay_us(15250);
			   //nodelay_ms(5);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
	
			   delay_ms(100);
			 
         GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		 
			  max=0;
			 //OSMutexPost(key2close);
		//	 OSSemPost(key1close);
			 key3=1;
			  break;
		}
         }
	if(key3==0){max=0; OSSemPost(sem2_switch1open);}
	}
	}
	} //end

	void sd1(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem2_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
	  if(key3==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_13));						        
		    if((b>=0)&&(b<=5))
			  //if(b==0)
		   {					   
		       // delay_ms(13); 
					delay_us(13550);
				// delay_us(700);
			GPIO_ResetBits(GPIOB,GPIO_Pin_12); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_13); 
		 //PC11->0
					delay_us(7000);
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

void sa1(void *pdata)
{    u8 err;
    u16 max=0,a,i,j;
	
	while(1)
	{
	   OSSemPend(sem2_switch2open,0,&err);
	// OSMutexPend(key2open, 0, &err);
//	OSSemPend(key2open, 0, &err);
    if(key4==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_15));	
//	    delay_us(10); 
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {	
		 if((abs(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_15)))>=max*995/1000)
		{ 	 // delay_ms(16);
		      delay_us(15250);  
		GPIO_SetBits(GPIOB,GPIO_Pin_14);
		GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			   delay_ms(100);
         GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
			  max=0;
			  key4=1;
			 //OSMutexPost(key2close);
			// OSSemPost(key2close);	    
			  break;
		}
         }	
		 if(key4==0) {max=0;OSSemPost(sem2_switch2open);}
	 
	}
	}
	} //end

	void sb1(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem2_switch2close,0,&err);
	//OSMutexPend(key2close, 0, &err);
	// OSSemPend(key2close, 0, &err);
	if(key4==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_6)-Get_Adc2(ADC_Channel_14));					        
		   if((b>=0)&&(b<=3))
		{	// delay_us(20000);
		//	  b=abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_13));						        
		  // if((b>=0)&&(b<=4))
		  // if(b==0)
		   {					   
		        // delay_ms(13);      //Í¶ÇĞÑÓÊ±
				// delay_us(700);
			
				 delay_us(13550);

			GPIO_ResetBits(GPIOB,GPIO_Pin_14); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  //PC11->0
			   delay_us(7000);
			 delay_ms(100);//Âö³åÑÓÊ±
			
		 GPIO_ResetBits(GPIOB,GPIO_Pin_14);
		 GPIO_ResetBits(GPIOB,GPIO_Pin_15);
             // OSSemPost(key2open);    
			//OSMutexPost(key2open);
			  key4=0;
			 break;
		   }
		   }
   		  }
   }	  
   }
   }


 /************************************************************/

//¼àÌıÉÏÎ»»úÈÎÎñ
void key_task(void *pdata)  
{			    						 
	while(1)
	{ 
		if(!INPUT1)
			{ OSSemPost(sem1_switch1open);
              OSSemPost(sem1_switch2open);
			 }//·¢ËÍÏûÏ¢
		if(INPUT1)
			{ OSSemPost(sem1_switch1close);
		      OSSemPost(sem1_switch2close);
			 }//·¢ËÍÏûÏ¢
		if(!INPUT1)
			{ OSSemPost(sem2_switch1open);
              OSSemPost(sem2_switch2open);
			 }//·¢ËÍÏûÏ¢
		if(INPUT1)
			{ OSSemPost(sem2_switch1close);
		      OSSemPost(sem2_switch2close);
			 }//·¢ËÍÏûÏ¢
 		delay_ms(500);
 	
	}
}

 
