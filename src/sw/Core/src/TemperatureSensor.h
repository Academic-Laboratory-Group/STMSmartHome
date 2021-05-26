#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

#include "gpio.h"
#include "SensorListener.h"
#include "Utils.h"
#include "EventManager.h"

class TemperatureSensor
{
	private:
		EventManager* m_eventManager;
		GPIO_TypeDef* m_GPIOx; 
		Sensor m_sensor;
			
	public:
		TemperatureSensor(EventManager* eventManager, Sensor sensor);
		void update();
		int getSensorValue();

};
	
#endif
