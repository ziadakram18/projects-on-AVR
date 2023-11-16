
 /*
 * main.c
 *
 *  Created on: Nov 15, 2023
 *      Author: YN
 */
#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "DIO_interface.h"
#include "BUZ_interface.h"
#include "SSD_interface.h"


void main()
{
	SSD_Type ssd={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

	SSD_voidInitialDataPort(ssd);

	SSD_voidEnable(ssd);

	BUZ_Type BUZ1= {BUZ_PORTD,BUZ_PIN7,ACTIVE_LOW};

	BUZ_voidInit(BUZ1);

	LED_Type arr[9]={{LED_PORTA,LED_PIN0,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN1,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN2,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN3,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN4,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN5,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN6,ACTIVE_HIGH},
				     {LED_PORTA,LED_PIN7,ACTIVE_HIGH},
					 {LED_PORTD,LED_PIN7,ACTIVE_HIGH}};
	for(int i=0 ; i<8 ; i++)
			{
				LED_voidInit(arr[i]);
			}
	while(1)
	{
		for(int i=0 ; i<10 ; i++)
				{
					switch(i){
					    case 0 :
					    	SSD_voidSendNumber(ssd,i);
					    	_delay_ms(1000);
					    	break;
					    case 1 :
					    	SSD_voidSendNumber(ssd,i);
					    	LED_voidOn(arr[i-1]);
					    	_delay_ms(1000);
					    	break;
					    case 2 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<2 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 3 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<3 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 4 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<4 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 5 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<5 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 6 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<6 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					        break;
					    case 7 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<7 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 8 :
					    	SSD_voidSendNumber(ssd,i);
					    	for(int i=0 ; i<8 ; i++)
					    	{
					    		LED_voidOn(arr[i]);
					    	}
					    	_delay_ms(1000);
					    	break;
					    case 9 :
					    	SSD_voidSendNumber(ssd,i);
					    	LED_voidOn(arr[8]);
					    	_delay_ms(1000);
					    	LED_voidOff(arr[8]);
					    	break;

					}

				}
		for(int i=0 ; i<8 ; i++)
					{
						LED_voidOff(arr[i]);
					}
	}

}



