#ifndef SRC_ROOMBUILDER_H_
#define SRC_ROOMBUILDER_H_

#include "ControllerFactory.h"

#include <string>

class RoomBuilder
{
	public:
		RoomBuilder() = default;
		~RoomBuilder() = default;

		void setName(std::string name);
		void addSensor(int PinId);
		void addController(ControllerFactory controllerFactory,
				int PinId, std::string name);
};
#endif /* SRC_ROOMBUILDER_H_ */
