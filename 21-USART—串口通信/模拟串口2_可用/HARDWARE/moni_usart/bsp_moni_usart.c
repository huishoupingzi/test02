#include "bsp_moni_usart.h"  

//TX      PA4

//波特率9600
  
//IO口引脚定义
void VirtualCOM_TX_GPIOConfig(void)
{
        GPIO_InitTypeDef GPIO_InitStruct;
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
        /* PA4设为数据输出口，模拟TX */
        
        GPIO_InitStruct.GPIO_Pin = COM_TX_PIN;
        GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;     //设置为推挽输出
        GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_Init(COM_TX_PORT, &GPIO_InitStruct); 
        GPIO_SetBits(COM_TX_PORT, COM_TX_PIN);           //设置默认位为高电平
}
   
//定义了数据发送引脚即可利用串口通信协议，间隔一定延时对单个bit位进行传输

//模拟引脚发送单个字节
void VirtualCOM_ByteSend(u8 val)
{
        u8 i = 0;
        COM_DATA_LOW;             //引脚拉低，即将发送数据
        delay_us(BuadRate9600);  //延时104us
        for(i = 0; i < 8; i++) //8位数据位
        {
            if(val & 0x01)    //如果bit位为1
                    COM_DATA_HIGH;  //引脚拉高
            else    //否则拉低
                    COM_DATA_LOW;
            delay_us(BuadRate9600);
            val >>= 1;
        }
        COM_DATA_HIGH;   //停止位
        delay_us(BuadRate9600);
}

//有了单个字节的发送函数，直接调用该函数即可发送字符串

void VirtualCOM_StringSend(u8 *str)
{
        while(*str != 0)
        {
                VirtualCOM_ByteSend(*str);
                str++;
        }
}






























