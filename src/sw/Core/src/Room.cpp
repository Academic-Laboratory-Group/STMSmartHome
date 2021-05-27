#include "Room.h"

float Room::getTemperature()
{
	return{};
}

void Room::setName(std::string name)
{
	m_name = std::move(name);
}

std::string Room::getName() const
{
	return m_name;
}

void Room::setControllerValue(int controllerId, float value)
{

}
