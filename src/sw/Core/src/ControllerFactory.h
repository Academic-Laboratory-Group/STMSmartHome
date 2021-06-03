#ifndef SRC_CONTROLLERFACTORY_H_
#define SRC_CONTROLLERFACTORY_H_

#include "Controller.h"

#include <memory>


class ControllerFactory
{
public:
	ControllerFactory() = default;
	virtual ~ControllerFactory() = default;

	virtual std::shared_ptr<Controller> createController(int pinIterator) = 0;
};


#endif /* SRC_CONTROLLERFACTORY_H_ */
