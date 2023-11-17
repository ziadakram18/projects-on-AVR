/*
 * main.c
 *
 *  Created on: Nov 17, 2023
 *      Author: YN
 */


#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SW_interface.h"
#include "LED_interface.h"

void main()
{
	LED_Type led1={LED_PORTA , LED_PIN0 , ACTIVE_HIGH};
	SW_Type sw1={DIO_u8PORTD , DIO_u8PIN0 , SW_Ext_PULL_UP};
	SW_Type sw2={DIO_u8PORTD , DIO_u8PIN1 , SW_Ext_PULL_DOWN};
	SW_voidInit(sw1);
	SW_voidInit(sw2);
	LED_voidInit(led1);

	while(1)
	{
		if(SW_u8GetPressed(sw1) || SW_u8GetPressed(sw2))
		{
			LED_voidOn(led1);
			_delay_ms(1000);
			LED_voidOff(led1);
		}

	}

}
