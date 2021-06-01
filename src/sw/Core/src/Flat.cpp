#include "Flat.h"
#include "TemperatureSensor.h"
#include "PWMControllerFactory.h"
#include "SwitchFactory.h"
#include "gpio.h"

#include <algorithm>
#include <memory>


Flat::Flat() : m_rooms(std::make_shared<std::vector<std::shared_ptr<Room>>>())
{
	m_sensors.push_back(std::make_unique<TemperatureSensor>(GPIO_PIN_8)); // TODO: more pins and sensors
}

void Flat::update(float)
{
	std::for_each(m_sensors.begin(), m_sensors.end(),
			[](auto& sensor){ sensor->update(); });
	std::for_each(m_rooms->begin(), m_rooms->end(),
			[](auto& room){ room->update(); });
}

void Flat::addRoom(std::shared_ptr<Room> room)
{
	m_sensors.at(0)->getEventManager()->subscribe(room);
	room->addController(std::make_unique<PWMControllerFactory>(), 0); // TODO: Set correct pins
	room->addController(std::make_unique<SwitchFactory>(), 1);
	m_rooms->push_back(std::move(room));
}

const Flat::Rooms Flat::getRooms() const
{
	return m_rooms;
}
