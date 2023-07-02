/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: SkYTop
 */
#include "stdTypes.h"
#include "errorStates.h"
#include "DIO_int.h"
#include <util/delay.h>
int main (){

	u8 i;

	DIO_enuInit();

	while(1){


		for(i=0;i<8;i++)
				{
					DIO_enuSetPinValue(DIO_u8PORTA,i,DIO_u8HIGH);
					_delay_ms(500);
				}





	}
/*
		for(i=0;i<10;i++)
		{
			DIO_enuSetPortValue(DIO_u8PORTA,segCthe[i]);
			_delay_ms(500);
		}

	}
*/
	return 0;
}

