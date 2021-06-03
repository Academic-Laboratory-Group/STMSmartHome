#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

#include "Utils.h"


class Controller
{
public:
	Controller(int pinIterator, ControllerType type) :
		m_pinIterator(pinIterator), m_type(type) {};
	virtual ~Controller() = default;

	virtual void setValue(float value) = 0;

	virtual ControllerType getType()
	{
		return m_type;
	}

protected:
	const int m_pinIterator{-1};
	const ControllerType m_type;
};

#endif /* SRC_CONTROLLER_H_ */
