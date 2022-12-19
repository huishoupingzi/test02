#ifndef __BSP_MONI_USART_H
#define __BSP_MONI_USART_H	 
#include "sys.h"
#include "stm32f10x_exti.h"

#include "sys.h"
#include "delay.h"

#define BuadRate9600 104
#define BuadRate1200 830

#define COM_REC_LEN 200              //�����������ֽ��� 200

#define COM_TX_PORT GPIOA  
#define COM_TX_PIN GPIO_Pin_4

#define COM_RX_PORT GPIOA
#define COM_RX_PIN GPIO_Pin_5

#define COM_RX PAout(5)  
#define COM_DATA_HIGH GPIO_SetBits(COM_TX_PORT, GPIO_Pin_4)   //�ߵ�ƽ
#define COM_DATA_LOW  GPIO_ResetBits(COM_TX_PORT, GPIO_Pin_4) //�͵�ƽ

#define COM_RX_STAT GPIO_ReadInputDataBit(COM_RX_PORT, GPIO_Pin_5)

enum {
        COM_START_BIT, //ֹͣλ
        COM_D0_BIT, //bit0
        COM_D1_BIT, //bit1
        COM_D2_BIT, //bit2
        COM_D3_BIT, //bit3
        COM_D4_BIT, //bit4
        COM_D5_BIT, //bit5
        COM_D6_BIT, //bit6
        COM_D7_BIT, //bit7
        COM_STOP_BIT,  //����λ
};

extern u8 recvStat;
extern u8 recvData;

extern u8 COM_RX_BUF[COM_REC_LEN];   //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 COM_RX_STA;                            //����״̬��� 
extern u8 COM_RX_END;

void VirtualCOM_TX_GPIOConfig(void);
void VirtualCOM_ByteSend(u8 val);
void VirtualCOM_StringSend(u8 *str);

void VirtualCOM_RX_GPIOConfig(void);
void EXTI9_5_IRQHandler(void);
void CLR_Buf(void);

#endif






























