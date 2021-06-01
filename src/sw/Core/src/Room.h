#ifndef SRC_ROOM_H_
#define SRC_ROOM_H_

#include "TemperatureSensor.h"
#include "Controller.h"
#include "ControllerFactory.h"

#include <string>
#include <memory>
#include <limits>


class Room : public SensorListener, Updatable
{
	public:
		Room() : m_controllers() {};
		~Room() = default;

		void update(float deltaTime = 0.f) override;

		void setName(std::string name);
		std::string getName() const;
		void setIntensity(int intensity);
		int getIntensity() const;
		void setHeaterTemperature(float temperature);
		float getTemperature() const;

		void addController(std::unique_ptr<ControllerFactory> controllerFactory,
				int pin);

		// SensorListener
		void notify(SensorType sensorType, float value);
		// !SensorListener

	private:
		std::string m_name{""};
		float m_temperature{std::numeric_limits<float>::infinity()};
		int m_intensity{50};
		float m_temperatureToSet{0};
		std::vector<std::shared_ptr<Controller>> m_controllers;

};

#endif /* SRC_ROOM_H_ */
