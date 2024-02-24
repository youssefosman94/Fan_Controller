/*******************************************************
 * Module       : LM35 Sensor
 *
 * Description  : Temperature Sensor
 *
 * File Name    : lm35_sencor.c
 *
 * Author       : Youssef Osman
 * ******************************************************/

/******************************      Includes       **************************/
#include"lm35_sensor.h"
#include"adc.h"

/****************************** Functions Definitions ************************/

uint8 LM35_getTemperature(void)
{
	uint16 adcDigitalValue =0;
	uint8 temp = 0;
	/* Read ADC channel where the temperature sensor is connected */
	adcDigitalValue = ADC_readChannel(SENSOR_CHANNEL_ID);
	/* Calculate Temperature*/
	temp = (uint8)(((uint32)adcDigitalValue*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp;
}
