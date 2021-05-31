#include "TemperatureSensor.h"
#include "Sensor_Driver.h"
#include "Utils.h"

TemperatureSensor::TemperatureSensor(int sensorPin) :
	Sensor(sensorPin, GPIOC)
{

}

void TemperatureSensor::update(float)
{
	m_eventManager->notify(SensorType::Temperature, getSensorValue());
}

float TemperatureSensor::getSensorValue()
{
	if (DS18B20_Init(m_GPIOx, m_sensorPin))
	{
		DS18B20_Write(0xCC, m_GPIOx, m_sensorPin);
		DS18B20_Write(0x44, m_GPIOx, m_sensorPin);
		if (!DS18B20_Init(m_GPIOx, m_sensorPin))
		{
			DS18B20_Write(0xCC, m_GPIOx, m_sensorPin);
			DS18B20_Write(0xBE, m_GPIOx, m_sensorPin);
			int temp = DS18B20_Read(m_GPIOx, m_sensorPin);
			temp |= DS18B20_Read(m_GPIOx, m_sensorPin) << 8;
			return temp;
		}
	}
	return 0;
}


