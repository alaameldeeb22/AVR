/*
 * Seven_Segment_config.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: SkYTop
 */

#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"

SEG_t SEVSEG_AstrSegConfig [SEG_NUM] =
{
{               DIO_u8PORTA, DIO_u8PIN0,
				DIO_u8PORTA, DIO_u8PIN1,
				DIO_u8PORTA, DIO_u8PIN2,
				DIO_u8PORTA, DIO_u8PIN3,
				DIO_u8PORTA, DIO_u8PIN4,
				DIO_u8PORTA, DIO_u8PIN5,
				DIO_u8PORTA, DIO_u8PIN6,
				NOT_CONNECTED,NOT_CONNECTED,
				NOT_CONNECTED,NOT_CONNECTED,
				COMMEN_CATHODE},//seg0

{               DIO_u8PORTB, DIO_u8PIN0,
				DIO_u8PORTB, DIO_u8PIN1,
				DIO_u8PORTB, DIO_u8PIN2,
				DIO_u8PORTB, DIO_u8PIN3,
				DIO_u8PORTB, DIO_u8PIN4,
				DIO_u8PORTB, DIO_u8PIN5,
				DIO_u8PORTB, DIO_u8PIN6,
				NOT_CONNECTED,NOT_CONNECTED,
				NOT_CONNECTED,NOT_CONNECTED,
				COMMEN_CATHODE},//seg1


};

