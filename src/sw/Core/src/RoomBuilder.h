#ifndef SRC_ROOMBUILDER_H_
#define SRC_ROOMBUILDER_H_

#include <iostream>

class RoomBuilder
{
	public:
		RoomBuilder() = default;
		~RoomBuilder() = default;

		void setName(std::string name);
		void addSensor(int PinId, std::string name);
		void addController(int PinId, std::string name);
};
#endif /* SRC_ROOMBUILDER_H_ */
