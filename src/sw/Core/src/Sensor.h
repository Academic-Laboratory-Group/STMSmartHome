#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

#include "EventManager.h"
#include "Updatable.h"
#include "Pinout.h"


class Sensor : public Updatable
{
public:
	Sensor(Pin pin) :
		m_pin(pin),
		m_eventManager(std::make_shared<EventManager>()) {};
	virtual ~Sensor() = default;

	virtual std::shared_ptr<EventManager> getEventManager()
	{
		return m_eventManager;
	}

protected:
	virtual float getSensorValue() = 0;

	Pin m_pin;
	std::shared_ptr<EventManager> m_eventManager;
};

#endif /* SRC_SENSOR_H_ */
