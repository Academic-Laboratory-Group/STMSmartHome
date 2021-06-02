#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

#include "EventManager.h"
#include "Updatable.h"


class Sensor : public Updatable
{
public:
	Sensor(int sensorPin, GPIO_TypeDef* GPIOx) :
		m_sensorPin(sensorPin), m_GPIOx(GPIOx),
		m_eventManager(std::make_shared<EventManager>()) {};
	virtual ~Sensor() = default;

	virtual std::shared_ptr<EventManager> getEventManager()
	{
		return m_eventManager;
	}

protected:
	virtual float getSensorValue() = 0;

	int m_sensorPin;
	GPIO_TypeDef* m_GPIOx;
	std::shared_ptr<EventManager> m_eventManager;
};

#endif /* SRC_SENSOR_H_ */
