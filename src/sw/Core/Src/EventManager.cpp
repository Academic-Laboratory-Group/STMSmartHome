#include "EventManager.h"
#include <algorithm>

void EventManager::subscribe(SensorListener* listener)
{
	listeners.push_back(listener);
}
void EventManager::unsubscribe(SensorListener* listener)
{
	listeners.erase(std::remove(listeners.begin(), listeners.end(), listener), listeners.end());
}

void EventManager::notify(Sensor sensor, int value)
{
	for (int i = 0; i < listeners.size(); ++i)
	{
		listeners[i]->notify(sensor, value);
	}
}