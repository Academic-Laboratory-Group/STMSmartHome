#include "Flat.h"
#include "TemperatureSensor.h"
#include "gpio.h"

Flat::Flat() : m_roomBuilder(std::make_shared<RoomBuilder>()),
m_rooms(std::make_shared<std::vector<std::shared_ptr<Room>>>())
{
	m_sensors.push_back(std::make_unique<TemperatureSensor>(GPIO_PIN_8));
}

void Flat::addRoom(std::shared_ptr<Room> room)
{
	m_sensors.at(0)->getEventManager()->subscribe(room);
	m_rooms->push_back(std::move(room));
}

const Flat::Rooms Flat::getRooms() const
{
	return m_rooms;
}

const std::shared_ptr<RoomBuilder> Flat::getBuilder() const
{
	return m_roomBuilder;
}
