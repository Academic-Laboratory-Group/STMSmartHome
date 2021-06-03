#ifndef SRC_PWMCONTROLLER_H_
#define SRC_PWMCONTROLLER_H_

#include "Controller.h"
#include "tim.h"


class PWMController : public Controller
{
public:
	PWMController(int pinIterator) :
		Controller(pinIterator, ControllerType::PWM)
	{
		HAL_TIM_PWM_Start(g_PWMPinOut.at(pinIterator).htim,
				g_PWMPinOut.at(pinIterator).channel);
		setValue(50.f);
	};
	~PWMController() = default;

	void setValue(float value) override
	{
		const auto pinOut = g_PWMPinOut.at(m_pinIterator);
		__HAL_TIM_SET_COMPARE(pinOut.htim, pinOut.channel,
				static_cast<int>(value));
	}
};

#endif /* SRC_PWMCONTROLLER_H_ */
