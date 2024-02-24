/*******************************************************
 *
 * Module       : ADC
 *
 * Description  : Source file for ADC Driver
 *
 * File Name    : adc.c
 *
 * Author : Youssef Osman
 *
 * ***************************************************/


/*****************************        Includes       ***************************/
#include"adc.h"
#include<avr/io.h>
#include"common_macros.h"
/****************************** Functions Definitions ***************************/

void ADC_init(const ADC_ConfigType * Config_ptr)
{
	ADMUX &= 0XE0; /* this is for initialization*/
	SET_BIT(ADCSRA,ADEN);                               /* Enable ADC*/
	ADMUX = (ADMUX & 0X3F)  | ((Config_ptr->Vref)<<6);  /* select reference voltage*/
	ADCSRA =(ADCSRA & 0XF8) | ((Config_ptr->clock));    /* select clock */

}

/*
 * this function for read channel pin (from 0 to 7) which we need to convert to digital
 * return digital value
 * */
uint16 ADC_readChannel(uint8 channel)
{
	ADMUX  = (ADMUX &0XE0) | (channel &0X07); /* select channel */
	SET_BIT(ADCSRA,ADSC);                     /* start conversion*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));         /* flag check*/
	SET_BIT(ADCSRA,ADIF);                     /* Clear flag*/
	return ADC;
}
