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
	SSD_Type ssd1={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

	SSD_voidInitialDataPort(ssd1);

	SSD_voidEnable(ssd1);

	while(1)
	{

		for(int i=0 ; i<7 ; i++)
		{
			SSD_voidSendNumber(ssd1,i);
			_delay_ms(100);

		}
	}

}
