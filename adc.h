/*******************************************************
 *
 * Module       : ADC
 *
 * Description  : Header file for ADC Driver
 *
 * File Name    : adc.h
 *
 * Author : Youssef Osman
 *
 * ***************************************************/

#ifndef ADC_H_
#define ADC_H_

/******************************      Includes       ****************************/

#include"std_types.h"

/*****************************      Definitions     ****************************/

#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/******************************     Declarations    ****************************/

/* Determine ADC clock through CPU Frequency and PreScaler*/
typedef enum {
	F_CPU_CLK_2_0,F_CPU_CLK_2_1,F_CPU_CLK_4,F_CPU_CLK_8,F_CPU_CLK_16,F_CPU_CLK_32,F_CPU_CLK_64,F_CPU_CLK_128
}ADC_ClockType;

/*Determine Reference Voltage and ADC Range*/
typedef enum {
	ADC_AREF,ADC_AVCC,ADC_INTERNAL =3
}ADC_ReferenceVoltage;

/*********** ADC Configurations ***************/
typedef struct {
	ADC_ClockType clock;
	ADC_ReferenceVoltage Vref;
}ADC_ConfigType;



/****************************** Functions Prototypes ***************************/


void ADC_init(const ADC_ConfigType * Config_ptr);

uint16 ADC_readChannel(uint8);


#endif /* ADC_H_ */
