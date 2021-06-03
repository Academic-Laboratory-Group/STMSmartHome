#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <limits> 	// std::numeric_limits

std::string float2str(float v);

RoomSettingsMenuState::RoomSettingsMenuState(
		std::shared_ptr<StateManager> stateManager, std::shared_ptr<Room> room) :
		State(stateManager), m_room(room), m_intensityToSet(room->getIntensity())
{
	const auto roomTemperature = m_room->getTemperature();
	if(roomTemperature != std::numeric_limits<float>::infinity())
		m_temperatureToSet = roomTemperature;

	// make new GUI
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");

	m_guiBuilder.addTextBox(240, 35, "Room name: " + m_room->getName(), 20u);

	m_guiBuilder.addCircle(140, 200, 75);
	m_guiBuilder.addTextBox(140, 200, "Light", 24u, BUTTON_TEXT_COLOR);
	m_guiBuilder.addCircle(340, 200, 75);
	m_guiBuilder.addTextBox(340, 200, "Heater", 24u, BUTTON_TEXT_COLOR);

	m_guiBuilder.addTextBox(155, 225, std::to_string(m_intensityToSet), 20u,
			BUTTON_TEXT_COLOR, BUTTON_BACKGROUND_COLOR, 60u, 30u);
	m_guiBuilder.addButton(140, 145, 40, 40, "+", ButtonShape::Circle,
			BUTTON_BACKGROUND_COLOR, 20u, RED);
	m_guiBuilder.addButton(140, 255, 40, 40, "-", ButtonShape::Circle,
			BUTTON_BACKGROUND_COLOR, 20u, BLUE);

	m_guiBuilder.addTextBox(340, 225, float2str(m_temperatureToSet), 20u,
			BUTTON_TEXT_COLOR, BUTTON_BACKGROUND_COLOR, 60u, 30u);
	m_guiBuilder.addButton(340, 145, 40, 40, "+", ButtonShape::Circle,
			BUTTON_BACKGROUND_COLOR, 20u, RED);
	m_guiBuilder.addButton(340, 255, 40, 40, "-", ButtonShape::Circle,
			BUTTON_BACKGROUND_COLOR, 20u, BLUE);

	if (roomTemperature != std::numeric_limits<float>::infinity())
	{
		m_guiBuilder.addTextBox(115, 85, "Temperature:", 20u);
		m_guiBuilder.addTextBox(230, 85, float2str(m_room->getTemperature()),20u);
		m_guiBuilder.addTextBox(275, 85, "*C", 20u);
	}

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void RoomSettingsMenuState::update(float deltaTime)
{
	if (m_room->getTemperature() != std::numeric_limits<float>::infinity())
		m_gui.setTextBoxText(static_cast<int>(TextBoxes::RoomTemperatureValue),
				float2str(m_room->getTemperature()));
}

void RoomSettingsMenuState::render()
{
	m_gui.render();
}

void RoomSettingsMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	const auto inputResultStr = m_gui.getButtonText(inputResult);

	if(inputResultStr == "BACK")
	{
		m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
		return;
	}
	else
	{
		switch(inputResult)
		{
			case (int)Buttons::LightUp:
				if (m_intensityToSet < 100)
					m_intensityToSet += 10;
				break;
			case (int)Buttons::LightDown:
				if (m_intensityToSet > 0)
					m_intensityToSet -= 10;
				break;
			case (int)Buttons::HeaterUp:
				m_temperatureToSet += 0.1f;
				break;
			case (int)Buttons::HeaterDown:
				m_temperatureToSet -= 0.1f;
				break;
			default:
				assert(!("InputResult out of range."));
		}

		m_room->setIntensity(m_intensityToSet);
		m_room->setHeaterTemperature(m_temperatureToSet);

		m_gui.setTextBoxText(static_cast<int>(TextBoxes::Intensity),
				std::to_string(m_intensityToSet));
		m_gui.setTextBoxText(static_cast<int>(TextBoxes::Temperature),
				float2str(m_temperatureToSet));
	}

}

std::string float2str(float v)
{
	auto tmp = static_cast<int>(v);
	auto integerStr = std::to_string(tmp);
	tmp = static_cast<int>((v - static_cast<float>(tmp)) * 10.f);
	auto fractionStr = std::to_string(tmp);

	return integerStr + '.' + fractionStr;
}
