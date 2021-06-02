#ifndef SRC_SWITCH_H_
#define SRC_SWITCH_H_

#include "Controller.h"


class Switch : public Controller
{
public:
	Switch(int pin) :
		Controller(pin, ControllerType::Switch) {};
	~Switch() = default;

	void setValue(float value) override
	{
		if (value)
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
		else
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
	}
};

#endif /* SRC_SWITCH_H_ */
