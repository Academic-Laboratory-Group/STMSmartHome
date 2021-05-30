#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "SensorListener.h"
#include "Utils.h"

#include <vector>
#include <memory>


class EventManager
{
	public:
		void subscribe(std::shared_ptr<SensorListener> listener);
		void unsubscribe(std::shared_ptr<SensorListener> listener);
		void notify(SensorType sensorType, float value);

	private:
		std::vector<std::shared_ptr<SensorListener>> m_listeners;
};
	
#endif
