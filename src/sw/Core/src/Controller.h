#ifndef SRC_CONTROLLER_H_
#define SRC_CONTROLLER_H_

class Controller
{
public:
	Controller() = default;
	virtual ~Controller() = default;

	virtual void setValue(float value) = 0;
};

#endif /* SRC_CONTROLLER_H_ */
