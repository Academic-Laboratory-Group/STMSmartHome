#ifndef SRC_SWITCH_H_
#define SRC_SWITCH_H_

#include "Controller.h"


class Switch : public Controller
{
public:
	Switch() = default;
	~Switch() = default;

	void setValue(float value) override
	{

	}
};

#endif /* SRC_SWITCH_H_ */
