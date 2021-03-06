
#include <string.h>
#include "board.h"
#include "hal_key.h"
#include "tim-board.h"
#include "timer_handles.h"
#include <stdlib.h>
#include "flash.h"

void Init() {
   
    BoardInitMcu();
    BoardInitPeriph();
    keys_init();
    setTimer2Callback(Time2Handler);
    Tim2McuInit(1);
		
	 
}

void KeyDownHandler(void) {
	
}
void handlerPre10Ms(void) {
    for (int delay = 0; delay < 30; delay++) {
        HAL_Delay(10);
        
    }
}

uint8_t tmp[20];

void delay(uint16_t t){
	while(t--);
}
int main( void )
{
	char liang[]={0x00,0x04,0x04,0x74,0x54,0x54,0x55,0x56,0x54,0x54,0x54,0x74,0x04,0x04,0x00,0x00,
	0x84,0x83,0x41,0x21,0x1D,0x05,0x05,0x05,0x05,0x05,0x7D,0x81,0x81,0x85,0xE3,0x00,};
	char deng[] = {0x80,0x70,0x00,0xFF,0x20,0x10,0x04,0x04,0x04,0x04,0xFC,0x04,0x04,0x04,0x04,0x00,
	0x80,0x60,0x18,0x07,0x08,0x30,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,};
	char mo[]={0x10,0x10,0xD0,0xFF,0x90,0x14,0xE4,0xAF,0xA4,0xA4,0xA4,0xAF,0xE4,0x04,0x00,0x00,
	0x04,0x03,0x00,0xFF,0x00,0x89,0x4B,0x2A,0x1A,0x0E,0x1A,0x2A,0x4B,0x88,0x80,0x00,};
	char shi[]={0x10,0x10,0x90,0x90,0x90,0x90,0x90,0x10,0x10,0xFF,0x10,0x10,0x11,0x16,0x10,0x00,
	0x00,0x20,0x60,0x20,0x3F,0x10,0x10,0x10,0x00,0x03,0x0C,0x10,0x20,0x40,0xF8,0x00,};
	char chang[]={0x20,0x18,0x08,0xEA,0xAC,0xA8,0xA8,0xAF,0xA8,0xA8,0xAC,0xEA,0x08,0x28,0x18,0x00,
	0x00,0x00,0x3E,0x02,0x02,0x02,0x02,0xFF,0x02,0x02,0x12,0x22,0x1E,0x00,0x00,0x00,};
	char hu[]={0x00,0xFC,0x04,0x04,0xFC,0x00,0x04,0x14,0x64,0x04,0xFE,0x02,0x43,0x32,0x00,0x00,
	0x00,0x0F,0x04,0x04,0x0F,0x00,0x01,0x01,0x41,0x81,0x7F,0x01,0x01,0x01,0x01,0x00,};
	char xi[]={0x00,0xFC,0x04,0x04,0xFC,0x02,0x02,0xFE,0x02,0x02,0x62,0x5A,0x46,0xC0,0x00,0x00,
	0x00,0x0F,0x04,0x04,0x4F,0x30,0x8E,0x81,0x46,0x28,0x10,0x28,0x46,0x81,0x80,0x00,};
	char jiao[]={0x08,0x08,0x88,0x68,0x08,0x08,0x09,0x0E,0x08,0x08,0x88,0x28,0x48,0x88,0x08,0x00,
	0x80,0x81,0x40,0x40,0x21,0x22,0x14,0x08,0x14,0x22,0x41,0x40,0x80,0x81,0x80,0x00,};
	char ti[]={0x10,0x94,0x54,0x34,0x1F,0x34,0x54,0x80,0x54,0x34,0x1F,0x34,0x54,0x94,0x90,0x00,
	0x01,0x00,0x00,0xFF,0x49,0x49,0x49,0x49,0x49,0x49,0x49,0xFF,0x00,0x00,0x00,0x00,};
	char fh[]={0x00,0x00,0x80,0x40,0x20,0x10,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x01,0x02,0x04,0x08,0x10,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
	char mie[]={0x02,0x02,0x82,0x72,0x02,0x02,0x02,0xFE,0x02,0x02,0x82,0x42,0x32,0x02,0x02,0x00,
	0x80,0x81,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0x80,0x80,0x00,};
	char null[32];
	uint32_t mm=0;
	uint32_t nn=1;
	uint16_t one=2;
	uint32_t low;
	mm=PrintFlashTest(0x08000800);
	//unsigned char wenzi[][32]={
	//};
	OLED_Init();  
	OLED_Clear();
	Init();
	OLED_ShowCHineseArray(85,2,fh);
	OLED_ShowCHineseArray(0,0,mo);
	OLED_ShowCHineseArray(16,0,shi);
	OLED_ShowChar(32,0,':');
	OLED_ShowChar(0,2,'1');
	OLED_ShowChar(10,2,'.');
	OLED_ShowCHineseArray(21,2,liang);
	OLED_ShowCHineseArray(37,2,deng);
	OLED_ShowCHineseArray(53,2,mo);
	OLED_ShowCHineseArray(69,2,shi);
	OLED_ShowChar(0,4,'2');
	OLED_ShowChar(10,4,'.');
	OLED_ShowCHineseArray(21,4,hu);
	OLED_ShowCHineseArray(37,4,xi);
	OLED_ShowCHineseArray(53,4,mo);
	OLED_ShowCHineseArray(69,4,shi);
	OLED_ShowChar(0,6,'3');
	OLED_ShowChar(10,6,'.');
	OLED_ShowCHineseArray(21,6,jiao);
	OLED_ShowCHineseArray(37,6,ti);
	OLED_ShowCHineseArray(53,6,mo);
	OLED_ShowCHineseArray(69,6,shi);
    while(1)
    {
			OLED_ShowCHineseArray(85,one,fh);	
			if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == 0){//key2 del
				HAL_Delay(10);
				if(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == 0){
					while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13) == 0);			
					OLED_ShowCHineseArray(85,one,null);	
					one-=2;
					if(one==0){one=6;}
				}
			}
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == 0){//key3 add
				HAL_Delay(10);
				if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == 0){
					while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1) == 0);
					OLED_ShowCHineseArray(85,one,null);	
					one+=2;
					if(one==8){one=2;}
				}
			}
		
			if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == 0){//key4
				HAL_Delay(10);
				if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == 0){
					while(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_5) == 0);
				nn++;
				switch(nn){
						case 2:GpioToggle(&Led2);GpioToggle(&Led1);break;
						case 3:
								GpioWrite(&Led1,1);
							GpioWrite(&Led2,1);
						while( 1 )
							 {		
		
			for(low = 0;low <1000;low++){
				GpioToggle(&Led1);
				GpioToggle(&Led2);
				delay(1000 - low);
				GpioToggle(&Led1);
				GpioToggle(&Led2);
				delay(low);
			}
			for(low = 1000;low >0;low--){
				GpioToggle(&Led1);
				GpioToggle(&Led2);
				delay(1000 - low);
				GpioToggle(&Led1);
				GpioToggle(&Led2);
				delay(low);
			}
	};break;
						case 4:while(1){
						GpioWrite(&Led1,1);
						GpioWrite(&Led2,0);
						HAL_Delay(1000);
						GpioWrite(&Led2,1);
						GpioWrite(&Led1,0);
						HAL_Delay(1000);
					};break;
						default:break;nn=1;
					
				if(nn==4){nn=1;}
					uint32_t save=one;
					WriteFlashTest(0x08000800,one);
				
						
					
					
					
	}

}
}
}
		}
