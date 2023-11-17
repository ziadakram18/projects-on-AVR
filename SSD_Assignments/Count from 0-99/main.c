/*
 * main.c
 *
 *  Created on: Nov 12, 2023
 *      Author: YN
 */


#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"

void main()
{
	SSD_Type ssd1={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTD,SSD_PIN0};
	SSD_Type ssd2={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTD,SSD_PIN1};

	SSD_voidInitialDataPort(ssd1);
	SSD_voidInitialDataPort(ssd2);

	while(1)
	{
		for(int j=0 ; j<10 ; j++)
		{
		    for(int i=0; i<10 ; i++)
		    {
		    	SSD_voidEnable(ssd1);
		    	SSD_voidSendNumber(ssd1,j);
		    	_delay_ms(170);
		    	SSD_voidDisable(ssd1);
		    	SSD_voidEnable(ssd2);
		    	SSD_voidSendNumber(ssd2,i);
		    	_delay_ms(170);
		    	SSD_voidDisable(ssd2);
		    	_delay_ms(300);
		    }
		}

	}

}
