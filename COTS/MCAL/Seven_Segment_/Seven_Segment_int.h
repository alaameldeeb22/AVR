/*
 * Seven_Segment_int.h
 *
 *  Created on: ??�/??�/????
 *      Author: SkYTop
 */

#ifndef SEVEN_SEGMENT_INT_H_
#define SEVEN_SEGMENT_INT_H_

ES_t Seven_Segment_enuInit(void);

ES_t Seven_Segment_enuDisplayNum(u8 Copy_u8Num);

ES_t Seven_Segment_enuEnableCommon(void);

ES_t Seven_Segment_enuDisableCommon(void);

ES_t Seven_Segment_enuEnableDot(void);

ES_t Seven_Segment_enuDisableDot(void);

ES_t Seven_Segment_enuClearDisplay(void);

#endif /* SEVEN_SEGMENT_INT_H_ */
