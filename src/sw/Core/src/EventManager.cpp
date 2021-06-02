#include "EventManager.h"

#include <algorithm>


void EventManager::subscribe(std::shared_ptr<SensorListener> listener)
{
	m_listeners.push_back(listener);
}
void EventManager::unsubscribe(std::shared_ptr<SensorListener> listener)
{
	m_listeners.erase(std::remove(m_listeners.begin(), m_listeners.end(), listener),
			m_listeners.end());
}

void EventManager::notify(SensorType sensorType, float value)
{
	for (const auto& listener : m_listeners)
	{
		listener->notify(sensorType, value);
	}
}
