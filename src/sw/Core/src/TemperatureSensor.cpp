#include "TemperatureSensor.h"
#include "Sensor_Driver.h"
#include "Utils.h"

TemperatureSensor::TemperatureSensor(Pin pin) :
	Sensor(pin)
{

}

void TemperatureSensor::update(float)
{
	m_eventManager->notify(SensorType::Temperature, getSensorValue());
}

float TemperatureSensor::getSensorValue()
{
	if (DS18B20_Init(m_pin.GPIO, m_pin.pin))
	{
		DS18B20_Write(0xCC, m_pin.GPIO, m_pin.pin);
		DS18B20_Write(0x44, m_pin.GPIO, m_pin.pin);
		if (DS18B20_Init(m_pin.GPIO, m_pin.pin))
		{
			DS18B20_Write(0xCC, m_pin.GPIO, m_pin.pin);
			DS18B20_Write(0xBE, m_pin.GPIO, m_pin.pin);
			int temp = DS18B20_Read(m_pin.GPIO, m_pin.pin);
			temp |= DS18B20_Read(m_pin.GPIO, m_pin.pin) << 8;
			return static_cast<float>(temp) * 0.0625f;
		}
	}
	return 0;
}


