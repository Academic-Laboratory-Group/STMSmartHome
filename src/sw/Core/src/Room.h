#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "TemperatureSensor.h"
#include "Controller.h"
#include "RoomBuilder.h"

#include <string>
#include <memory>


class Room : private RoomBuilder
{
	public:
		Room() : m_sensor(), m_controllers() {};
		~Room() = default;

		float getTemperature();
		void setName(std::string name);
		std::string getName() const;
		void setControllerValue(int controllerId, float value);

	private:
		std::string m_name{"Room"};
		std::shared_ptr<TemperatureSensor> m_sensor;
		std::vector<Controller> m_controllers;

};

#endif /* SRC_ROOM_H_ */
