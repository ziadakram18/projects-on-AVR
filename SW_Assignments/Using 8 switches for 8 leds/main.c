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
#include "LED_interface.h"
#include "DIO_interface.h"
#include "SW_interface.h"

void main(void)
{
	SW_Type  sw[8]={{DIO_u8PORTD , DIO_u8PIN0 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN1 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN2 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN3 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN4 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN5 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN6 , SW_Ext_PULL_UP},
					{DIO_u8PORTD , DIO_u8PIN7 , SW_Ext_PULL_UP}};

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

	for(int i=0 ; i<8 ; i++)
		{
		SW_voidInit(sw[i]);
		}
	while(1)
	{
		u8 GetArray[8]={0,0,0,0,0,0,0,0};
		for(int i=0 ; i<8 ; i++)
		{
			GetArray[i]=SW_u8GetPressed(sw[i]);
		}

	    if(GetArray[0] == 1)
	    {
	    	for(int i=0 ; i<8 ; i++)
	    			{
	    			 	 LED_voidOn(arr[i]);
	    			}
		 	_delay_ms(1000);
	    	for(int i=0 ; i<8 ; i++)
	    		   {
	    		    	LED_voidOff(arr[i]);
	    		   }
	    }

	    else if(GetArray[1] == 1)
	    {
		        		for(int i=0 ; i<8 ; i++)
		        			{
		        			 	 LED_voidOn(arr[i]);
		        			 	_delay_ms(250);
		        			 	LED_voidOff(arr[i]);
		        			}

		 }


	    else if(GetArray[2] == 1)
	    	    {
		         		for(int i=7 ; i>=0 ; i--)
		         			{
		         			 	 LED_voidOn(arr[i]);
		         			 	_delay_ms(250);
		         			 	LED_voidOff(arr[i]);
		         			}

		         	}


	    else if(GetArray[3] == 1)
	    	    {
			    	for(int i=0,j=7 ; i<4,j>3 ; i++,j--)
			    		{
			    		 	 LED_voidOn(arr[i]);
			    		 	 LED_voidOn(arr[j]);
			    		 	 _delay_ms(250);
			    		}
			    	for(int i=0 ; i<8 ; i++)
			    		{
			    			LED_voidOff(arr[i]);
			    		}
			    	 _delay_ms(250);

			    }

	    else if(GetArray[4] == 1)
	    	    {
		         		for(int i=3,j=4 ; i>=0,j<8 ; i--,j++)
		         			{
		         			 	 LED_voidOn(arr[i]);
		         			 	 LED_voidOn(arr[j]);
		         			 	 _delay_ms(250);
		         			}
		         		for(int i=0 ; i<8 ; i++)
		         			{
		         				LED_voidOff(arr[i]);
		         			}
		         		 _delay_ms(250);

		         	}


	    else if(GetArray[5] == 1)
	    	    {
		        		for(int i=0 ; i<8 ; i++)
		        			{
		        				LED_voidOn(arr[i]);
		        				 _delay_ms(250);
		        				 LED_voidOff(arr[i]);
		        				 _delay_ms(250);
		        			}


		        		 for(int i=7 ; i>=0 ; i--)
		        		 	{
		        		 		LED_voidOn(arr[i]);
		        		 		 _delay_ms(250);
		        		 		 LED_voidOff(arr[i]);
		        		 		 _delay_ms(250);
		        		 	}

		        	}

	    else if(GetArray[6] == 1)
	    	    {
		     		for(int i=0 ; i<8 ; i++)
		     			{
		     				LED_voidOn(arr[i]);
		     				 _delay_ms(250);
		     			}

		     		for(int i=0 ; i<8 ; i++)
		     			{
		     				LED_voidOff(arr[i]);
		     			}
		     		_delay_ms(250);
		     	}


	    else if(GetArray[7] == 1)
	    	    {
				     for(int i=0,j=7 ; i<4,j>3 ; i++,j--)
				     	{
				     		LED_voidOn(arr[i]);
				     		LED_voidOn(arr[j]);
				     		 _delay_ms(250);
				     		 LED_voidOff(arr[i]);
				     		 LED_voidOff(arr[j]);
				     		 _delay_ms(250);
				     	}

				     for(int i=3,j=4 ; i>=0,j<8 ; i--,j++)
				     	{
				     		LED_voidOn(arr[i]);
				     		LED_voidOn(arr[j]);
				     		 _delay_ms(250);
				     		LED_voidOff(arr[i]);
				     		LED_voidOff(arr[j]);
				     		_delay_ms(250);
				     	}
				  }

	 }

}



