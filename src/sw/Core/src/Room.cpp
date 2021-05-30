#include "Room.h"

void Room::setName(std::string name)
{
	m_name = std::move(name);
}

std::string Room::getName() const
{
	return m_name;
}

void Room::setIntensity(int intensity)
{
	m_intensity = intensity;
}

int Room::getIntensity() const
{
	return m_intensity;
}

void Room::setHeaterTemperature(float temperature)
{
	m_temperatureToSet = temperature;
}

float Room::getTemperature() const
{
	return m_temperature;
}

void Room::notify(SensorType sensorType, float value)
{
	if(sensorType == SensorType::Temperature)
		m_temperature = value;
}
