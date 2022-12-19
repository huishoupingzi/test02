#include "bsp_moni_usart.h"  

//TX      PA4

//������9600
  
//IO�����Ŷ���
void VirtualCOM_TX_GPIOConfig(void)
{
        GPIO_InitTypeDef GPIO_InitStruct;
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
        /* PA4��Ϊ��������ڣ�ģ��TX */
        
        GPIO_InitStruct.GPIO_Pin = COM_TX_PIN;
        GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;     //����Ϊ�������
        GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(COM_TX_PORT, &GPIO_InitStruct); 
        GPIO_SetBits(COM_TX_PORT, COM_TX_PIN);           //����Ĭ��λΪ�ߵ�ƽ
}
   
//���������ݷ������ż������ô���ͨ��Э�飬���һ����ʱ�Ե���bitλ���д���

//ģ�����ŷ��͵����ֽ�
void VirtualCOM_ByteSend(u8 val)
{
        u8 i = 0;
        COM_DATA_LOW;             //�������ͣ�������������
        delay_us(BuadRate9600);  //��ʱ104us
        for(i = 0; i < 8; i++) //8λ����λ
        {
            if(val & 0x01)    //���bitλΪ1
                    COM_DATA_HIGH;  //��������
            else    //��������
                    COM_DATA_LOW;
            delay_us(BuadRate9600);
            val >>= 1;
        }
        COM_DATA_HIGH;   //ֹͣλ
        delay_us(BuadRate9600);
}

//���˵����ֽڵķ��ͺ�����ֱ�ӵ��øú������ɷ����ַ���

void VirtualCOM_StringSend(u8 *str)
{
        while(*str != 0)
        {
                VirtualCOM_ByteSend(*str);
                str++;
        }
}






























