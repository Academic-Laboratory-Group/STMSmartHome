#ifndef SRC_PWMCONTROLLER_H_
#define SRC_PWMCONTROLLER_H_

#include "Controller.h"


class PWMController : public Controller
{
public:
	PWMController(int pin) :
		Controller(pin, ControllerType::PWM) {};
	~PWMController() = default;

	void setValue(float value) override
	{

	}
};

#endif /* SRC_PWMCONTROLLER_H_ */
