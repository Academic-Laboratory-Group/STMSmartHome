#ifndef _EVENTMANAGER_H_
#define _EVENTMANAGER_H_

#include "TemperatureSensor.h"
#include "Utils.h"
#include <vector>

class EventManager
{
	private:
		std::vector <TemperatureSensor> m_subscribers;
	
	public:
		std::vector <int> temperatures;
		void subscribe(TemperatureSensor observers);
		void unsubscribe(TemperatureSensor observers);
		void notify();

};
	
#endif
