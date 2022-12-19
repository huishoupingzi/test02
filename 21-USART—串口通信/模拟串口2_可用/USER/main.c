/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �������ԣ��ж�ģʽ/EXTIģʽ��
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� F103-MINI STM32 ������ 
  * ��̳    :http://www.firebbs.cn
  * �Ա�    :https://fire-stm32.taobao.com
  *
  ******************************************************************************
  */ 

#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_exti.h" 
#include "delay.h"     
#include "bsp_moni_usart.h"      
  
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */ 
int main(void)
{
  u8 a=3;
  
	/* LED �˿ڳ�ʼ�� */
	VirtualCOM_TX_GPIOConfig();    
   delay_init();  
	  	

	while(1)                            
	{
    VirtualCOM_StringSend((u8*)"�ú�ѧϰ\r\n");   
//    VirtualCOM_ByteSend(a);
    delay_ms(500);
	} 
}


/*********************************************END OF FILE**********************/
