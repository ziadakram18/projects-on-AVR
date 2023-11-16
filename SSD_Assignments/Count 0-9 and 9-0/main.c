/*
 * main.c
 *
 *  Created on: Nov 11, 2023
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
	SSD_Type ssd={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

	SSD_voidInitialDataPort(ssd);

	SSD_voidEnable(ssd);
	while(1)
	{
		for(int i=0 ; i<10 ; i++)
		{
			SSD_voidSendNumber(ssd,i);
			_delay_ms(1000);
		}
		for(int i=9 ; i>=0 ; i--)
		{
			SSD_voidSendNumber(ssd,i);
			_delay_ms(1000);
		}

	}

}
