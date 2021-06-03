#include "Flat.h"
#include "TemperatureSensor.h"
#include "PWMControllerFactory.h"
#include "SwitchFactory.h"
#include "Pinout.h"

#include <algorithm>
#include <memory>


Flat::Flat() : m_rooms(std::make_shared<std::vector<std::shared_ptr<Room>>>())
{
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
	if(g_sensorsPinOutIterator < g_sensorsPinOut.size())
	{
		m_sensors.push_back(std::make_unique<TemperatureSensor>(
				g_sensorsPinOut[g_sensorsPinOutIterator]));
		m_sensors.at(g_sensorsPinOutIterator)->getEventManager()->subscribe(room);
		++g_sensorsPinOutIterator;
	}
	if(g_switchPinOutIterator < g_switchPinOut.size())
	{
		room->addController(std::make_unique<SwitchFactory>(),
				g_switchPinOutIterator);
		++g_switchPinOutIterator;
	}
	if(g_PWMPinOutIterator < g_PWMPinOut.size())
	{
		room->addController(std::make_unique<PWMControllerFactory>(),
				g_PWMPinOutIterator);
		++g_PWMPinOutIterator;
	}
	m_rooms->push_back(std::move(room));
}

const Flat::Rooms Flat::getRooms() const
{
	return m_rooms;
}
