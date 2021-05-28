#include "Room.h"

float Room::getTemperature() const
{
	return m_temperature;
}

void Room::setName(std::string name)
{
	m_name = std::move(name);
}

void Room::setTemperature(float temperature)
{
	m_temperature = std::move(temperature);
}

std::string Room::getName() const
{
	return m_name;
}

void Room::setControllerValue(int controllerId, float value)
{

}
