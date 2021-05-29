#include "Room.h"

int Room::getTemperature() const
{
	return m_temperature;
}

void Room::setName(std::string name)
{
	m_name = std::move(name);
}

void Room::setTemperature(int temperature)
{
	m_temperature_to_change = temperature;
}

void Room::setIntensity(int intensity)
{
	m_intensity_to_change = intensity;
}

int Room::getIntensity() const
{
	return m_intensity;
}

std::string Room::getName() const
{
	return m_name;
}

std::shared_ptr<TemperatureSensor> Room::getSensor()
{
	return m_sensor;
}

void Room::setControllerValue(int controllerId, float value)
{

}
