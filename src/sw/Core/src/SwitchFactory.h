#ifndef SRC_SWITCHFACTORY_H_
#define SRC_SWITCHFACTORY_H_

#include "ControllerFactory.h"
#include "Controller.h"
#include "Switch.h"

#include <memory>


class SwitchFactory : public ControllerFactory
{
public:
	SwitchFactory() = default;
	~SwitchFactory() = default;

	std::shared_ptr<Controller> createController(int pinIterator) override
	{
		return std::make_shared<Switch>(pinIterator);
	}
};

#endif /* SRC_SWITCHFACTORY_H_ */
