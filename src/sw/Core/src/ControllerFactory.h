#ifndef SRC_CONTROLLERFACTORY_H_
#define SRC_CONTROLLERFACTORY_H_

#include "Controller.h"


class ControllerFactory
{
public:
	ControllerFactory() = default;
	virtual ~ControllerFactory() = default;

	virtual Controller createController() = 0;
};


#endif /* SRC_CONTROLLERFACTORY_H_ */
