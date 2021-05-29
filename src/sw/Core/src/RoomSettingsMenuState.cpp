#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

RoomSettingsMenuState::RoomSettingsMenuState(
		std::shared_ptr<StateManager> stateManager, std::shared_ptr<Room> room) :
		State(stateManager), m_room(room), m_temperature_to_change(room->getTemperature()),
		m_intensity_to_change(room->getIntensity())
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");

	m_guiBuilder.addTextBox(240, 35, "Room name: " + m_room->getName(), 20u);

	m_guiBuilder.addButton(140, 195, 150, 150, "Light", Circle);
	m_guiBuilder.addButton(340, 195, 150, 150, "Heater", Circle);

	if (m_room->getSensor() != NULL)
	{
		m_guiBuilder.addTextBox(115, 85, "Temperature:", 20u);
		m_guiBuilder.addTextBox(220, 85, std::to_string(m_room->getTemperature()),20u);
		m_guiBuilder.addTextBox(270, 85, "*C", 20u);

		m_guiBuilder.addTextBox(140, 218, std::to_string(m_intensity_to_change), 20u);
		m_guiBuilder.addTextBox(140, 142, "+", 20u, RED);
		m_guiBuilder.addTextBox(140, 246, "-", 20u, BLUE);

		m_guiBuilder.addTextBox(340, 210, std::to_string(m_temperature_to_change), 20u);
		m_guiBuilder.addTextBox(340, 142, "+", 20u, RED);
		m_guiBuilder.addTextBox(340, 246, "-", 20u, BLUE);
	}

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void RoomSettingsMenuState::update(float deltaTime)
{
	if (m_room->getSensor() != NULL)
		m_gui.setTextBoxText(2, std::to_string(m_room->getTemperature()));
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
	else if(inputResultStr == "Light" && (m_room->getSensor() == NULL))
	{
		m_stateManager->changeState(std::make_unique<NewDeviceControllingSignalMenuState>(m_stateManager, m_room));
		return;
	}
	else if(inputResultStr == "Heater")
	{
		m_stateManager->changeState(std::make_unique<NewDeviceControllingSignalMenuState>(m_stateManager, m_room));
		return;
	}
	else if (m_room->getSensor() != NULL)
	{
		switch(inputResult)
		{
			case (int)Buttons::LightUp:
				m_intensity_to_change += 10;
				return;
			case (int)Buttons::LightDown:
				m_intensity_to_change -= 10;
				return;
			case (int)Buttons::HeaterUp:
				m_temperature_to_change += 1;
				return;
			case (int)Buttons::HeaterDown:
				m_temperature_to_change -= 1;
				return;
			default:
				assert(!("InputResult out of range."));
		}
	}
	else
	{
		assert(!("InputResult out of range."));
	}

	m_gui.setTextBoxText(5, std::to_string(m_intensity_to_change));
	m_gui.setTextBoxText(9, std::to_string(m_temperature_to_change));

	m_room->setTemperature(m_temperature_to_change);
	m_room->setIntensity(m_intensity_to_change);
}
