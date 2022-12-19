/**
  ******************************************************************************
  * @file    main.c
  * @author  fire
  * @version V1.0
  * @date    2013-xx-xx
  * @brief   �����жϽ��ղ���
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
#include "bsp_usart.h"  
  





/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */  
  
int main(void)
{	

  u8 a[]={0x00,0x01,0x02,0x03,0x04};
  u16 num=sizeof(a)/sizeof(u8);

  /*��ʼ��USART ����ģʽΪ 115200 8-N-1���жϽ���*/
  USART_Config();

	
	/* ����һ���ַ��� */
	Usart_SendString( DEBUG_USARTx,"����һ�������жϽ��ջ���ʵ��\r\n");
	printf("��ӭʹ��Ұ��STM32������\r\n");
  Usart_SendArray( DEBUG_USARTx, a,num);      
  //    Usart_SendArray( DEBUG_USARTx, a); 

	
  while(1)
	{	
		
    
	}	
}
/*********************************************END OF FILE**********************/
