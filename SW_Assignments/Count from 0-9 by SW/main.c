#include <avr/io.h>
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SW_interface.h"

void main()
{
	SSD_Type ssd1={SSD_COMMON_CATHODE,SSD_PORTC,SSD_PORTC,SSD_PIN7};

	SW_Type sw={DIO_u8PORTD , DIO_u8PIN0 , SW_Int_PULL_UP};

	SSD_voidInitialDataPort(ssd1);

	SSD_voidEnable(ssd1);

	SW_voidInit(sw);


	u8 i=0 ;
	while(1)
	{
		while(i != 10){

				if(SW_u8GetPressed(sw)){
					while (SW_u8GetPressed(sw)){
						SSD_voidSendNumber(ssd1,i);

					}
		          i++;
				}
				}
		     i = 0;
			}

}

