#include "EventManager.h"

void EventManager::subscribe(TemperatureSensor observers)
{
	m_subscribers.push_back(observers);
}
void EventManager::unsubscribe(TemperatureSensor observers)
{

}

void EventManager::notify()
{
	temperatures.clear();
	for (int i = 0; i < m_subscribers.size(); i++)
	{
		temperatures.push_back(m_subscribers[i].update());
	}
}
