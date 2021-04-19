#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

#include "gpio.h"
#include "SensorObserver.h"
#include "Utils.h"

class TemperatureSensor
{
	private:
		GPIO_TypeDef* m_GPIOx; 
		uint16_t m_GPIO_pin;
			
	public:
		TemperatureSensor(ChooseSensor sensor);
		int update();

};
	
#endif
