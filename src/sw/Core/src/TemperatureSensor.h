#ifndef _TEMPERATURESENSOR_H_
#define _TEMPERATURESENSOR_H_

#include "EventManager.h"
#include "Sensor.h"
#include "Utils.h"
#include "Pinout.h"

class TemperatureSensor : public Sensor
{
	public:
		TemperatureSensor(Pin pin);
		~TemperatureSensor() = default;

		void update(float) override;

	private:
		float getSensorValue() override;
};
	
#endif
