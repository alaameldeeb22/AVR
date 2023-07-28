/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: SkYTop
 */
#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"
#include "Seven_Segment_config.h"
#include "Seven_Segment_int.h"

#include "util/delay.h"

extern SEG_t SEVSEG_AstrSegConfig[SEG_NUM];


int main(void){
DIO_enuInit();
Seven_Segment_enuInit (SEVSEG_AstrSegConfig);

	while(1){

		for(u8 i=0;i<10;i++){
			Seven_Segment_enuDisplayNum(0,i);
             for(u8 j=0;j<10;j++){
     			Seven_Segment_enuDisplayNum(1,j);
                 _delay_ms(200);
 }
		}
	}
	return 0;
}
