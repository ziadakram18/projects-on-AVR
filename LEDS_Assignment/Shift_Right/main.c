/*
 * main.c
 *
 *  Created on: Nov 10, 2023
 *      Author: YN
 */


#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "DIO_interface.h"

void main(void)
{
	LED_Type arr[8]={{LED_PORTA,LED_PIN0,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN1,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN2,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN3,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN4,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN5,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN6,ACTIVE_HIGH},
			         {LED_PORTA,LED_PIN7,ACTIVE_HIGH}};
	for(int i=0 ; i<8 ; i++)
	{
		LED_voidInit(arr[i]);
	}
	while(1)
	{
		for(int i=7 ; i>=0 ; i--)
			{
			 	 LED_voidOn(arr[i]);
			 	_delay_ms(250);
			 	LED_voidOff(arr[i]);
			}

	}

}

