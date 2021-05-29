#include "TemperatureSensor.h"
#include "Sensor_Driver.h"

TemperatureSensor::TemperatureSensor(EventManager* eventManager, Sensor sensor)
{
	m_eventManager = eventManager;
	m_GPIOx = GPIOC;
}

void TemperatureSensor::setSensor(Sensor sensor)
{
	m_sensor = sensor;
}
void TemperatureSensor::update()
{
	m_eventManager->notify(m_sensor, getSensorValue());
}

int TemperatureSensor::getSensorValue()
{
	if (DS18B20_Init(m_GPIOx, m_sensor))
	{
		DS18B20_Write (0xCC, m_GPIOx, m_sensor); 
		DS18B20_Write (0x44, m_GPIOx, m_sensor); 
		if (!DS18B20_Init(m_GPIOx, m_sensor)) 
		{
			DS18B20_Write (0xCC, m_GPIOx, m_sensor); 
			DS18B20_Write (0xBE, m_GPIOx, m_sensor); 
			int temp = DS18B20_Read (m_GPIOx, m_sensor); 
			temp |= DS18B20_Read (m_GPIOx, m_sensor) << 8; 
			return temp;
		}
	}
	return 0;
}


