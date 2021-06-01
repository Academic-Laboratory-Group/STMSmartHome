#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include "Utils.h"


class Controller
{
public:
	Controller(int pin, ControllerType type) :
		m_pin(pin), m_type(type) {};
	virtual ~Controller() = default;

	virtual void setValue(float value) = 0;

	virtual ControllerType getType()
	{
		return m_type;
	}

private:
	const int m_pin{-1};
	const ControllerType m_type;
};

#endif /* SRC_CONTROLLER_H_ */
