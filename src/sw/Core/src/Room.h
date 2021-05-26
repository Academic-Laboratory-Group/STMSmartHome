#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "TemperatureSensor.h"
#include "Controller.h"
#include "RoomBuilder.h"

class Room : private RoomBuilder
{
	public:
		Room() = default;
		~Room() = default;

		float getTemperature();
		void setControllerValue(int controllerId, float value);

	private:
		TemperatureSensor m_sensor;
		std::vector<Controller> m_controllers;

};

#endif /* SRC_ROOM_H_ */
