#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

RoomSettingsMenuState::RoomSettingsMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 50, 300, 40, 100);
	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);

	m_guiBuilder.addTextBox("Temperature:", BLACK, 115, 85, 20);
	//m_guiBuilder.addTextBox(to_str(m_temperature), BLACK, 220, 85, 20); //not working
	m_guiBuilder.addTextBox("*C" ,BLACK, 270, 85, 20);

	m_guiBuilder.addTextBox("Light", BLACK, 140, 195, 24);
	m_guiBuilder.addButton(Square, BACKGROUND, 138, 145, 60, 60);
	m_guiBuilder.addTextBox("+", RED, 138, 145, 24);
	m_guiBuilder.addButton(Square, BACKGROUND, 138, 240, 60, 60);
	m_guiBuilder.addTextBox("-", BLACK, 138, 240, 24);

	m_guiBuilder.addTextBox("Heater", BLACK, 345, 195, 24);
	m_guiBuilder.addButton(Square, BACKGROUND, 338, 145, 60, 60);
	m_guiBuilder.addTextBox("+", RED, 338, 145, 24);
	m_guiBuilder.addButton(Square, BACKGROUND, 338, 240, 60, 60);
	m_guiBuilder.addTextBox("-", BLACK, 338, 240, 24);

	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND, 140, 195, 150, 150);
	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND, 340, 195, 150, 150);
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
