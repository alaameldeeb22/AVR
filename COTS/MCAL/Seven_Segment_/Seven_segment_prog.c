#include "errorStates.h"
#include "stdTypes.h"

#include "DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"

ES_t Seven_Segment_enuInit(void){

	ES_t Local_enuErrorState = ES_NOK;

     u32 Local_u32Check=0;

Local_u32Check=DIO_enuSetPinDirection(SEG_APORT,SEG_APIN,DIO_u8OUTPUT);
Local_u32Check|=DIO_enuSetPinDirection(SEG_BPORT,SEG_BPIN,DIO_u8OUTPUT)<<3;
Local_u32Check|=DIO_enuSetPinDirection(SEG_CPORT,SEG_CPIN,DIO_u8OUTPUT)<<6;
Local_u32Check|=DIO_enuSetPinDirection(SEG_DPORT,SEG_DPIN,DIO_u8OUTPUT)<<9;
Local_u32Check|=DIO_enuSetPinDirection(SEG_EPORT,SEG_EPIN,DIO_u8OUTPUT)<<12;
Local_u32Check|=DIO_enuSetPinDirection(SEG_FPORT,SEG_FPIN,DIO_u8OUTPUT)<<15;
Local_u32Check|=DIO_enuSetPinDirection(SEG_GPORT,SEG_GPIN,DIO_u8OUTPUT)<<18;

#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_CMN_PORT,SEG_CMN,DIO_u8OUTPUT);
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error "your common pin in wrong selection"
#endif

#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD
	DIO_enuSetPinDirection(SEG_DOT_PORT,SEG_DOT,DIO_u8OUTPUT);
#elif SEG_DOT==NOT_CONNECTED || SEG_DOT_PORT == NOT_CONNECTED

#else
#error "your DOT pin in wrong selection"
#endif

	u8 Local_u8Itre =0;
	for(Local_u8Itre=0;Local_u8Itre<=21;Local_u8Itre+=3){

		if(( ((Local_u32Check) >>Local_u8Itre)&7)!= ES_OK){
			return Local_enuErrorState;
		}
	}
		Local_enuErrorState=ES_OK;

	return Local_enuErrorState;
}



ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num){

	ES_t Local_enuErrorState = ES_NOK;
if(Copy_u8Num<10){

	ES_t Local_enuErrorState = ES_NOK;

	     u32 Local_u32Check=0;

#if SEG_TYPE==COMMEN_ANODE

	Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
	Local_u32Check|=DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<3;
	Local_u32Check|=DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<6;
	Local_u32Check|=DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<9;
	Local_u32Check|=DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<12;
	Local_u32Check|=DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<15;
	Local_u32Check|=DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,!((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<18;


#elif SEG_TYPE==COMMEN_CATHODE

	    Local_u32Check=DIO_enuSetPinValue(SEG_APORT,SEG_APIN,((SEG_Au8NumDisplay[Copy_u8Num]>>0)&1));
		Local_u32Check|=DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>1)&1))<<3;
		Local_u32Check|=DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>2)&1))<<6;
		Local_u32Check|=DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>3)&1))<<9;
		Local_u32Check|=DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>4)&1))<<12;
		Local_u32Check|=DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>5)&1))<<15;
		Local_u32Check|=DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,((SEG_Au8NumDisplay[Copy_u8Num]>>6)&1))<<18;

#else
#error "SEG Type has wrong selection"
#endif
		u8 Local_u8Itre =0;
					for(Local_u8Itre=0;Local_u8Itre<=21;Local_u8Itre+=3){

						if((((Local_u32Check) >>Local_u8Itre)&7)!= ES_OK){
							return Local_enuErrorState;
					}
						Local_enuErrorState=ES_OK;
						}
}
else {
	Local_enuErrorState=ES_OUT_OF_RANGE;
}
	return Local_enuErrorState;
}



ES_t Seven_Segment_enuEnableCommon(void){

	ES_t Local_enuErrorState = ES_NOK;

#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD

#if SEG_TYPE==COMMEN_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);

#elif SEG_TYPE==COMMEN_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);
#else
#error "SEG Type has wrong selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error "your common pin in wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableCommon(void){

	ES_t Local_enuErrorState = ES_NOK;


#if SEG_CMN<=DIO_u8PIN7 && SEG_CMN_PORT<= DIO_u8PORTD

#if SEG_TYPE==COMMEN_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8HIGH);

#elif SEG_TYPE==COMMEN_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_CMN_PORT,SEG_CMN,DIO_u8LOW);
#else
#error "SEG Type has wrong selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error "your common pin in wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuEnableDot(void){

	ES_t Local_enuErrorState = ES_NOK;

#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD

#if SEG_TYPE==COMMEN_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT,DIO_u8HIGH);

#elif SEG_TYPE==COMMEN_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT,DIO_u8LOW);
#else
#error "SEG Type has wrong selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error "your DOT pin in wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuDisableDot(void){

	ES_t Local_enuErrorState = ES_NOK;

#if SEG_DOT<=DIO_u8PIN7 && SEG_DOT_PORT<= DIO_u8PORTD

#if SEG_TYPE==COMMEN_CATHODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT,DIO_u8LOW);

#elif SEG_TYPE==COMMEN_ANODE
	Local_enuErrorState = DIO_enuSetPinValue(SEG_DOT_PORT,SEG_DOT,DIO_u8HIGH);
#else
#error "SEG Type has wrong selection"
#endif
#elif SEG_CMN==NOT_CONNECTED || SEG_CMN_PORT == NOT_CONNECTED

#else
#error "your DOT pin in wrong selection"
#endif

	return Local_enuErrorState;
}

ES_t Seven_Segment_enuClearDisplay(void){

	ES_t Local_enuErrorState = ES_NOK;


#if SEG_TYPE==COMMEN_ANODE

DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_u8HIGH);
DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_u8HIGH);


#elif SEG_TYPE==COMMEN_CATHODE

DIO_enuSetPinValue(SEG_APORT,SEG_APIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_BPORT,SEG_BPIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_CPORT,SEG_CPIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_DPORT,SEG_DPIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_EPORT,SEG_EPIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_FPORT,SEG_FPIN,DIO_u8LOW);
DIO_enuSetPinValue(SEG_GPORT,SEG_GPIN,DIO_u8LOW);

#else
#error "SEG Type has wrong selection"
#endif

	return Local_enuErrorState;
}








