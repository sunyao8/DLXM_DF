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
//#include <math.h>
#include "adc.h"
 #include "task.h"
 /////////////////////////UCOSII任务堆栈设置///////////////////////////////////
//START 任务
//设置任务优先级
#define START_TASK_PRIO      			20 //开始任务的优先级设置为最低
//设置任务堆栈大小
#define START_STK_SIZE  				64
//创建任务堆栈空间	
OS_STK START_TASK_STK[START_STK_SIZE];
//任务函数接口
void start_task(void *pdata);	
 			   
//SWITCH2OPEN任务
//设置任务优先级
#define S1OPEN_TASK_PRIO       			5 
//设置任务堆栈大小
#define S1OPEN_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S1OPEN_TASK_STK[S1OPEN_STK_SIZE];
//任务函数接口
//void switch2open_task(void *pdata);
	void sa(void *pdata);
//SWITCH1OPEN任务
//设置任务优先级
#define S1CLOSE_TASK_PRIO       			6 
//设置任务堆栈大小
#define S1CLOSE_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE];
//任务函数接口
//void switch2close_task(void *pdata);
	  void sb(void *pdata);;


//SWITCH2OPEN任务
//设置任务优先级
#define S2OPEN_TASK_PRIO       			7
//设置任务堆栈大小
#define S2OPEN_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S2OPEN_TASK_STK[S2OPEN_STK_SIZE];
//任务函数接口
//void switch2open_task(void *pdata);
	void sc(void *pdata);
//SWITCH1OPEN任务
//设置任务优先级
#define S2CLOSE_TASK_PRIO       			8 
//设置任务堆栈大小
#define S2CLOSE_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE];
//任务函数接口
//void switch2close_task(void *pdata);
	  void sd(void *pdata);
/***************************************************************/

//SWITCH2OPEN任务
//设置任务优先级
#define S3OPEN_TASK_PRIO       			9 
//设置任务堆栈大小
#define S3OPEN_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S3OPEN_TASK_STK[S3OPEN_STK_SIZE];
//任务函数接口
//void switch2open_task(void *pdata);
	void sa1(void *pdata);
//SWITCH1OPEN任务
//设置任务优先级
#define S3CLOSE_TASK_PRIO       			10 
//设置任务堆栈大小
#define S3CLOSE_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE];
//任务函数接口
//void switch2close_task(void *pdata);
	  void sb1(void *pdata);;


//SWITCH2OPEN任务
//设置任务优先级
#define S4OPEN_TASK_PRIO       			11
//设置任务堆栈大小
#define S4OPEN_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S4OPEN_TASK_STK[S4OPEN_STK_SIZE];
//任务函数接口
//void switch2open_task(void *pdata);
	void sc1(void *pdata);
//SWITCH1OPEN任务
//设置任务优先级
#define S4CLOSE_TASK_PRIO       			12 
//设置任务堆栈大小
#define S4CLOSE_STK_SIZE  		    		128
//创建任务堆栈空间	
OS_STK S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE];
//任务函数接口
//void switch2close_task(void *pdata);
void sd1(void *pdata);

/**************************************************************/
//按键扫描任务
//设置任务优先级
#define KEY_TASK_PRIO       			3 
//设置任务堆栈大小
#define KEY_STK_SIZE  					64
//创建任务堆栈空间	
OS_STK KEY_TASK_STK[KEY_STK_SIZE];
//任务函数接口
void key_task(void *pdata);			  
//////////////////////////////////////////////////////////////////////////////
//OS_EVENT * msg_key;			//按键邮箱事件块指针
OS_EVENT * sem1_switch1open;		//沸藕帕恐刚�	 	   
OS_EVENT * sem1_switch1close;	
OS_EVENT * sem1_switch2open;	 //沸藕帕恐刚�			
OS_EVENT * sem1_switch2close; 
OS_EVENT * sem2_switch1open;	 //沸藕帕恐刚�			
OS_EVENT * sem2_switch1close;	 
OS_EVENT * sem2_switch2open;  //沸藕帕恐刚� 		 
OS_EVENT * sem2_switch2close; 
 INT8U e;
u8 key1=0,key2=0,key3=0,key4=0;


 int main(void)
 {	 
    delay_init();	    	 //延时函数初始化	  
	NVIC_Configuration(); 	 //设置NVIC中断分组2:2位抢占优先级，2位响应
	Adc_Init();
	deinit();
	OSInit();  	 			//初始化UCOSII		 			  
 	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//创建起始任务
	OSStart();	    
}

//开始任务
void start_task(void *pdata)
{
    OS_CPU_SR cpu_sr=0;
	pdata = pdata;
	
	sem1_switch1open=OSSemCreate(0);		//创建信号量
	sem1_switch1close=OSSemCreate(0);
	sem1_switch2open=OSSemCreate(0);		//创建信号量
	sem1_switch2close=OSSemCreate(0);
	sem2_switch1open=OSSemCreate(0);		//创建信号量
	sem2_switch1close=OSSemCreate(0);
	sem2_switch2open=OSSemCreate(0);		//创建信号量
	sem2_switch2close=OSSemCreate(0);
	
	OSStatInit();					//初始化统计任务.这里会延时1秒钟左右	
 	OS_ENTER_CRITICAL();			//进入临界区(无法被中断打断)    				    				   
    OSTaskCreate(sa,(void *)0,(OS_STK*)&S1OPEN_TASK_STK[S1OPEN_STK_SIZE-1],S1OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb,(void *)0,(OS_STK*)&S1CLOSE_TASK_STK[S1CLOSE_STK_SIZE-1],S1CLOSE_TASK_PRIO); 
	OSTaskCreate(sc,(void *)0,(OS_STK*)&S2OPEN_TASK_STK[S2OPEN_STK_SIZE-1],S2OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd,(void *)0,(OS_STK*)&S2CLOSE_TASK_STK[S2CLOSE_STK_SIZE-1],S2CLOSE_TASK_PRIO);
	OSTaskCreate(sa1,(void *)0,(OS_STK*)&S3OPEN_TASK_STK[S3OPEN_STK_SIZE-1],S3OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sb1,(void *)0,(OS_STK*)&S3CLOSE_TASK_STK[S3CLOSE_STK_SIZE-1],S3CLOSE_TASK_PRIO); 
	OSTaskCreate(sc1,(void *)0,(OS_STK*)&S4OPEN_TASK_STK[S4OPEN_STK_SIZE-1],S4OPEN_TASK_PRIO);						   	 				   
 	OSTaskCreate(sd1,(void *)0,(OS_STK*)&S4CLOSE_TASK_STK[S4CLOSE_STK_SIZE-1],S4CLOSE_TASK_PRIO);  
	OSTaskCreate(key_task,(void *)0,(OS_STK*)&KEY_TASK_STK[KEY_STK_SIZE-1],KEY_TASK_PRIO);	 				   
 		
	OSTaskSuspend(START_TASK_PRIO);	//挂起起始任务.
	OS_EXIT_CRITICAL();				//退出临界区(可以被中断打断)
}	  
//A1 A*1开关任务 峰值切 一号电容 继电器1 
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
	     a=abs(Get_Adc1(ADC_Channel_8)-Get_Adc2(ADC_Channel_1));	
		
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


//A1 * B1� 一号电容器 继电器1 过零投 
	void sd(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
	  if(key1==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_2)-Get_Adc2(ADC_Channel_1));						        
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


//一号电容 2号继电器 峰值切
void sa(void *pdata)
{    u8 err;
    u16 max=0,a,i,j;
	
	while(1)
	{
	   OSSemPend(sem1_switch2open,0,&err);
    if(key2==0)
	{	 for(i=1;i<500;i++)
        {
	     a=abs(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	 
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


//一号电容   2号 继电器  过零投
	void sb(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem1_switch2close,0,&err);
	if(key2==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_4));						        
		   if((b>0)&&(b<=4))
		{	 delay_us(20000);
			  b=abs(Get_Adc1(ADC_Channel_5)-Get_Adc2(ADC_Channel_4));						        
		   if((b>0)&&(b<=5))
		  // if(b==0)
		   {					   
		      
				 delay_us(14000);
			GPIO_ResetBits(GPIOB,GPIO_Pin_7); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_8);  //PC11->0
			   delay_us(7000);
			 delay_ms(100);//脉冲延时
			
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
 //A1 A*1开关任务	 A1点由Get_Adc1(ADC_Channel_13)，A*1由Get_Adc2(ADC_Channel_10) 过零投

//2号电容 1号继电器 峰值切
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
	     a=abs(Get_Adc1(ADC_Channel_8)-Get_Adc2(ADC_Channel_1));	
//		delay_us(10);
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {
	    		
		if((abs(Get_Adc1(ADC_Channel_8)-Get_Adc2(ADC_Channel_1)))>=max*800/1000)
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


//2号电容 1号继电器 过零投
	void sd1(void *pdata)
	{   u16 b;
	    u8 err;
		
	while(1)
		{ OSSemPend(sem2_switch1close,0,&err);
	  // OSSemPend(key1close, 0, &err);
	  if(key3==1)
  {   	
  		 while(1)
        { 	b=abs(Get_Adc1(ADC_Channel_1)-Get_Adc2(ADC_Channel_6));						        
		    if((b>0)&&(b<5))
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
//2号电容 2号继电器 峰值切
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
	     a=abs(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8));	
//	    delay_us(10); 
		
		 if(a>max)
		 max=a;
		 }
        for(j=1;j<600;j++)
        {	
		 if((abs(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_8)))>=max*995/1000)
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



//2号电容 2号继电器 过零投
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
        { 	b=abs(Get_Adc1(ADC_Channel_4)-Get_Adc2(ADC_Channel_7));					        
		   if((b>0)&&(b<3))
		{	// delay_us(20000);
		//	  b=abs(Get_Adc1(ADC_Channel_11)-Get_Adc2(ADC_Channel_13));						        
		  // if((b>=0)&&(b<=4))
		  // if(b==0)
		   {					   
		        // delay_ms(13);      //投切延时
				// delay_us(700);
			
				 delay_us(13550);

			GPIO_ResetBits(GPIOB,GPIO_Pin_14); //PD2->1
			GPIO_SetBits(GPIOB,GPIO_Pin_15);  //PC11->0
			   delay_us(7000);
			 delay_ms(100);//脉冲延时
			
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

//监听上位机任务
void key_task(void *pdata)  
{			    						 
	while(1)
	{ 
		if(INPUT1)
			{ OSSemPost(sem1_switch1open);
              OSSemPost(sem1_switch2open);
			 }//发送消息
		if(!INPUT1)
			{ OSSemPost(sem1_switch1close);
		      OSSemPost(sem1_switch2close);
			 }//发送消息
		if(INPUT2)
			{ OSSemPost(sem2_switch1open);
              OSSemPost(sem2_switch2open);
			 }//发送消息
		if(!INPUT2)
			{ OSSemPost(sem2_switch1close);
		      OSSemPost(sem2_switch2close);
			 }//发送消息
 		delay_ms(500);
 	
	}
}

 
