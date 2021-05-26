#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <iostream>
#include <string>
#include <sstream>


template < typename Type >
std::string to_str(const Type& t)
{
	std::ostringstream os;
	os << t;
	return os.str();
}

RoomSettingsMenuState::RoomSettingsMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 50, 300, 100, 40);
	m_guiBuilder.addTextBox("BACK", BUTTON_TEXT_COLOR, 50, 300, 20);

	m_guiBuilder.addTextBox("Temperature:", TEXT_COLOR, 115, 85, 20);
	//m_guiBuilder.addTextBox(to_str(m_temperature), BLACK, 220, 85, 20); //not working
	m_guiBuilder.addTextBox("*C" ,TEXT_COLOR, 270, 85, 20);

	m_guiBuilder.addTextBox("Light", TEXT_COLOR, 140, 195, 24);
	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 138, 145, 60, 60);
	m_guiBuilder.addTextBox("+", TEXT_COLOR, 138, 145, 24);
	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 138, 240, 60, 60);
	m_guiBuilder.addTextBox("-", TEXT_COLOR, 138, 240, 24);

	m_guiBuilder.addTextBox("Heater", TEXT_COLOR, 345, 195, 24);
	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 338, 145, 60, 60);
	m_guiBuilder.addTextBox("+", TEXT_COLOR, 338, 145, 24);
	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 338, 240, 60, 60);
	m_guiBuilder.addTextBox("-", TEXT_COLOR, 338, 240, 24);

	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND_COLOR, 140, 195, 150, 150);
	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND_COLOR, 340, 195, 150, 150);

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
			m_stateManager->changeState(std::make_shared<RoomChooseMenuState>(m_stateManager));
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
}
