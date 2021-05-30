#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "TemperatureSensor.h"
#include "Controller.h"
#include "RoomBuilder.h"

#include <string>
#include <memory>
#include <limits>


class Room : private RoomBuilder, public SensorListener
{
	public:
		Room() : m_controllers() {};
		~Room() = default;

		void setName(std::string name);
		std::string getName() const;
		void setIntensity(int intensity);
		int getIntensity() const;
		void setHeaterTemperature(float temperature);
		float getTemperature() const;

		// SensorListener
		void notify(SensorType sensorType, float value);
		// !SensorListener

	private:
		std::string m_name{""};
		float m_temperature{std::numeric_limits<float>::infinity()};
		int m_intensity{50};
		float m_temperatureToSet{0};
		int m_intensityToSet{50};
		std::vector<Controller> m_controllers;

};

#endif /* SRC_ROOM_H_ */
