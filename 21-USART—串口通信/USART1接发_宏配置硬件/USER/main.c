/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   串口中断接收测试
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
#include "bsp_usart.h"  
  





/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */  
  
int main(void)
{	

  u8 a[]={0x00,0x01,0x02,0x03,0x04};
  u16 num=sizeof(a)/sizeof(u8);

  /*初始化USART 配置模式为 115200 8-N-1，中断接收*/
  USART_Config();

	
	/* 发送一个字符串 */
	Usart_SendString( DEBUG_USARTx,"这是一个串口中断接收回显实验\r\n");
	printf("欢迎使用野火STM32开发板\r\n");
  Usart_SendArray( DEBUG_USARTx, a,num);      
  //    Usart_SendArray( DEBUG_USARTx, a); 

	
  while(1)
	{	
		
    
	}	
}
/*********************************************END OF FILE**********************/
