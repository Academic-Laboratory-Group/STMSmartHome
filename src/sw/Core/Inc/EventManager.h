#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "SensorObserver.h"
#include <vector>
#include "Utils.h"

class EventManager
{
	private:
		std::vector <SensorListener*> listeners;
	
	public:
		void subscribe(SensorListener* listener);
		void unsubscribe(SensorListener* listener);
		void notify(Sensor sensor, int value);

};
	
#endif
