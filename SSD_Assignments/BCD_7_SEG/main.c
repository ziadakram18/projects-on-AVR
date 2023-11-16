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
    u8 arr[9]={0b0000 , 0b0001 , 0b0010 , 0b0011 , 0b0100 , 0b0101 , 0b0110 , 0b0111 , 0b1000 , 0b1001};
	while(1)
	{

		for(int i=0 ; i<9 ; i++)
		{

			DIO_voidWriteLowNibbles(DIO_u8PORTC,arr[i]);
			_delay_ms(1000);

		}
	}

}
