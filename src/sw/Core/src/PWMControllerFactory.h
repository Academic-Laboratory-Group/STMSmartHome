#ifndef SRC_PWMCONTROLLERFACTORY_H_
#define SRC_PWMCONTROLLERFACTORY_H_

#include "ControllerFactory.h"
#include "Controller.h"
#include "PWMController.h"


class PWMControllerFactory : public ControllerFactory
{
public:
	PWMControllerFactory() = default;
	~PWMControllerFactory() = default;

	Controller createController() override
	{
		return Factory();
	}
};

#endif /* SRC_PWMCONTROLLERFACTORY_H_ */
