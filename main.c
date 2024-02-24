/**********************************************
 *
 * Author        : Youssef Osman
 * File Name     : main.c
 * Description   : Fan Controller project using LM35 Temperature Sensor and DC motor
 *
 * *******************************************/

#include"lcd.h"
#include"dc_motor.h"
#include"adc.h"
#include"lm35_sensor.h"
int main(void)
{

	uint8 temperature = 0;
	uint8 state_1[] = "OFF";
	uint8 state_2[] = "ON ";
	ADC_ConfigType ADC_configurations ={F_CPU_CLK_8,ADC_INTERNAL};

	ADC_init(&ADC_configurations);
	DC_MOTOR_init();
	LCD_init();
	LCD_moveCursor(0,3);
	LCD_displayString("FAN IS ");
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");


	while(1)
	{
		temperature = LM35_getTemperature();
		if(temperature<30)
		{
			LCD_displayStringRowColumn(0,10,state_1);
			DC_MOTOR_rotate(0,stop);
			LCD_moveCursor(1,10);
			LCD_intgerToString(temperature);
			LCD_displayCharacter(' ');
		}
		else
		{
			LCD_displayStringRowColumn(0,10,state_2);
			if(temperature>=30 && temperature<60)
				{
					DC_MOTOR_rotate(25,clockwise);
					LCD_moveCursor(1,10);
					LCD_intgerToString(temperature);
					LCD_displayCharacter(' ');
				}
			else if(temperature >= 60 && temperature<90)
				{
					DC_MOTOR_rotate(50,clockwise);
					LCD_moveCursor(1,10);
					LCD_intgerToString(temperature);
					LCD_displayCharacter(' ');
				}
			else if(temperature >=90 && temperature<120)
				{
					DC_MOTOR_rotate(75,clockwise);
					if(temperature>=100)
					{
						LCD_moveCursor(1,10);
						LCD_intgerToString(temperature);
					}
					else
					{
						LCD_moveCursor(1,10);
						LCD_intgerToString(temperature);
						LCD_displayCharacter(' ');
					}

				}
			else if(temperature>=120)
				{
					DC_MOTOR_rotate(100,clockwise);
					LCD_moveCursor(1,10);
					LCD_intgerToString(temperature);
				}
		}



	}

}

