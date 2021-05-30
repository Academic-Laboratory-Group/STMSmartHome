#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

#include "EventManager.h"
#include "Sensor.h"
#include "Utils.h"
#include "gpio.h"

class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor(int sensorPin);
		~TemperatureSensor() = default;

		void update() override;

	private:
		float getSensorValue() override;
};
	
#endif
