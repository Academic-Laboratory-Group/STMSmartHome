#include "TemperatureSensor.h"
#include "Sensor_Driver.h"

TemperatureSensor::TemperatureSensor(ChooseSensor sensor)
{
	if (sensor == Sensor1)
	{
		m_GPIOx = GPIOC;
		m_GPIO_pin = GPIO_PIN_8;
	}
	else if(sensor == Sensor2)
	{
		m_GPIOx = GPIOC;
		m_GPIO_pin = GPIO_PIN_6;
	}
	else if(sensor == Sensor3)
	{
		m_GPIOx = GPIOC;
		m_GPIO_pin = GPIO_PIN_5;
	}
		
}

int TemperatureSensor::update()
{
	if (DS18B20_Init(m_GPIOx, m_GPIO_pin))
	{
		DS18B20_Write (0xCC, m_GPIOx, m_GPIO_pin); // Send skip ROM command
		DS18B20_Write (0x44, m_GPIOx, m_GPIO_pin); // Send reading start conversion command
		if (!DS18B20_Init(m_GPIOx, m_GPIO_pin)) 
		{
			DS18B20_Write (0xCC, m_GPIOx, m_GPIO_pin); // Send skip ROM command
			DS18B20_Write (0xBE, m_GPIOx, m_GPIO_pin); // Read the register, a total of nine bytes, the first two bytes are the conversion value
			int temp = DS18B20_Read (m_GPIOx, m_GPIO_pin); // Low byte
			temp |= DS18B20_Read (m_GPIOx, m_GPIO_pin) << 8; // High byte
			return temp;
		}
	}
	return 0;
}
