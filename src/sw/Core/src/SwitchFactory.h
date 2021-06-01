#ifndef SRC_SWITCHFACTORY_H_
#define SRC_SWITCHFACTORY_H_

#include "ControllerFactory.h"
#include "Controller.h"
#include "Switch.h"


class SwitchFactory : public ControllerFactory
{
public:
	SwitchFactory() = default;
	~SwitchFactory() = default;

	Controller createController() override
	{
		return Switch();
	}
};

#endif /* SRC_SWITCHFACTORY_H_ */
