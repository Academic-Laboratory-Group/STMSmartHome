#ifndef SRC_PWMCONTROLLERFACTORY_H_
#define SRC_PWMCONTROLLERFACTORY_H_

#include "ControllerFactory.h"
#include "Controller.h"
#include "PWMController.h"

#include <memory>


class PWMControllerFactory : public ControllerFactory
{
public:
	PWMControllerFactory() = default;
	~PWMControllerFactory() = default;

	std::shared_ptr<Controller> createController(int pin) override
	{
		return std::make_shared<PWMController>(pin);
	}
};

#endif /* SRC_PWMCONTROLLERFACTORY_H_ */
