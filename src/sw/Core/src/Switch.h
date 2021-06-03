#ifndef SRC_SWITCH_H_
#define SRC_SWITCH_H_

#include "Controller.h"
#include "Pinout.h"


class Switch : public Controller
{
public:
	Switch(int pinIterator) :
		Controller(pinIterator, ControllerType::Switch) {};
	~Switch() = default;

	void setValue(float value) override
	{
		const auto pinOut = g_switchPinOut.at(m_pinIterator);
		if (value)
			HAL_GPIO_WritePin(pinOut.GPIO, pinOut.pin, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(pinOut.GPIO, pinOut.pin, GPIO_PIN_RESET);
	}
};

#endif /* SRC_SWITCH_H_ */
