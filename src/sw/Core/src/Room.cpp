#include "Room.h"
#include "Controller.h"
#include "Utils.h"

#include <algorithm>


void Room::update(float)
{
	// Heater
	if(m_temperature > m_temperatureToSet + 0.5f)
		// TODO: actually SwitchController means always HeaterController for now
		for_each(m_controllers.begin(), m_controllers.end(),
				[](auto& controller)
				{
					if(controller->getType() == ControllerType::Switch)
						controller->setValue(1.f);
				});

	if(m_temperature < m_temperatureToSet - 0.5f)
		for_each(m_controllers.begin(), m_controllers.end(),
				[](auto& controller)
				{
					if(controller->getType() == ControllerType::Switch)
						controller->setValue(0.f);
				});
}

void Room::setName(std::string name)
{
	m_name = std::move(name);
}

std::string Room::getName() const
{
	return m_name;
}

void Room::setIntensity(int intensity)
{	// TODO: actually PWMController means always LightIntensityController for now
	for_each(m_controllers.begin(), m_controllers.end(),
			[intensity](auto& controller)
			{
				if(controller->getType() == ControllerType::PWM)
					controller->setValue(static_cast<float>(intensity));
			});
}

int Room::getIntensity() const
{
	return m_intensity;
}

void Room::setHeaterTemperature(float temperature)
{
	m_temperatureToSet = temperature;
}

float Room::getTemperature() const
{
	return m_temperature;
}

void Room::addController(std::unique_ptr<ControllerFactory> controllerFactory,
		int pin)
{
	m_controllers.push_back(
			std::move(controllerFactory->createController(pin)));
}

void Room::notify(SensorType sensorType, float value)
{
	if(sensorType == SensorType::Temperature)
		m_temperature = value;
}
