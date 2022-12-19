/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   按键测试（中断模式/EXTI模式）
  ******************************************************************************
  * @attention
  *
  * 实验平台:野火 F103-MINI STM32 开发板 
  * 论坛    :http://www.firebbs.cn
  * 淘宝    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "delay.h"     
#include "bsp_moni_usart.h"      
  
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */ 
int main(void)
{
  u8 a=3;
  
	/* LED 端口初始化 */
	VirtualCOM_TX_GPIOConfig();    
   delay_init();  
	  	

	while(1)                            
	{
    VirtualCOM_StringSend((u8*)"好好学习\r\n");   
//    VirtualCOM_ByteSend(a);
    delay_ms(500);
	} 
}


/*********************************************END OF FILE**********************/
