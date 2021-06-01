#ifndef SRC_PWMCONTROLLER_H_
#define SRC_PWMCONTROLLER_H_

#include "Controller.h"
#include "tim.h"


class PWMController : public Controller
{
public:
	PWMController(int pin) :
		Controller(pin, ControllerType::PWM) {};
	~PWMController() = default;

	void setValue(float value) override
	{
		__HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_1,
				static_cast<int>(value));
	}
};

#endif /* SRC_PWMCONTROLLER_H_ */
