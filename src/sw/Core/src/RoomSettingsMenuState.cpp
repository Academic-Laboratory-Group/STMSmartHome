#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

RoomSettingsMenuState::RoomSettingsMenuState(
		std::shared_ptr<StateManager> stateManager, std::shared_ptr<Room> room) :
		State(stateManager), m_room(room), m_temperature(room->getTemperature())
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");

	m_guiBuilder.addTextBox(115, 85, "Temperature:", 20u);
	m_guiBuilder.addTextBox(220, 85,std::to_string(m_temperature),20u);
	m_guiBuilder.addTextBox(270, 85, "*C", 20u);

	m_guiBuilder.addTextBox(140, 195, "Light", 24u, BUTTON_TEXT_COLOR);
	m_guiBuilder.addButton(138, 145, 60, 60, "+");
	m_guiBuilder.addButton(138, 240, 60, 60, "-");

	m_guiBuilder.addTextBox(345, 195, "Heater", 24u, BUTTON_TEXT_COLOR);
	m_guiBuilder.addButton(338, 145, 60, 60, "+");
	m_guiBuilder.addButton(338, 240, 60, 60, "-");

	m_guiBuilder.addButton(140, 195, 150, 150, "", Circle);
	m_guiBuilder.addButton(340, 195, 150, 150, "", Circle);

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void RoomSettingsMenuState::update(float deltaTime)
{

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

	switch(inputResult)
	{
		case (int)Buttons::Back:
			m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
			return;
		case (int)Buttons::LightUp:
			return;
		case (int)Buttons::LightDown:
			return;
		case (int)Buttons::HeaterUp:
			m_temperature += 0.5;
			return;
		case (int)Buttons::HeaterDown:
			m_temperature -= 0.5;
			return;
		default:
			assert(!("InputResult out of range."));
	}

	m_room->setTemperature(m_temperature);
	m_gui.setTextBoxText(1, std::to_string(m_temperature));
}
