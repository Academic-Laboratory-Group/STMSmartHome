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

		void setName(std::string name);
		std::string getName() const;
		void setTemperature(int temperature);
		int getTemperature() const;
		void setIntensity(int intensity);
		int getIntensity() const;
		void setControllerValue(int controllerId, float value);
		std::shared_ptr<TemperatureSensor> getSensor();
	private:
		std::string m_name{""};
		int m_temperature = 20;
		int m_temperature_to_change = 0;
		int m_intensity = 50;
		int m_intensity_to_change = 0;
		std::shared_ptr<TemperatureSensor> m_sensor;
		std::vector<Controller> m_controllers;

};

#endif /* SRC_ROOM_H_ */
