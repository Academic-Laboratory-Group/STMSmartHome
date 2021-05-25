#include "RoomSettingsMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

RoomSettingsMenuState::RoomSettingsMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 50, 300, 100, 40);
	m_guiBuilder.addTextBox("BACK", BUTTON_TEXT_COLOR, 50, 300, 20);

	m_guiBuilder.addTextBox("Temperature:", TEXT_COLOR, 115, 85, 20);
	m_guiBuilder.addTextBox(m_temperature, TEXT_COLOR, 220, 85, 20);
	m_guiBuilder.addTextBox("*C" ,TEXT_COLOR, 270, 85, 20);

	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND_COLOR, 140, 195, 150, 150);
	m_guiBuilder.addTextBox("Light", BUTTON_TEXT_COLOR, 135, 195, 24);
	m_guiBuilder.addTextBox("+", BUTTON_TEXT_COLOR, 133, 145, 24);
	m_guiBuilder.addTextBox("-", BUTTON_TEXT_COLOR, 133, 240, 24);

	m_guiBuilder.addButton(Circle, BUTTON_BACKGROUND_COLOR, 340, 195, 150, 150);
	m_guiBuilder.addTextBox("Heater", BUTTON_TEXT_COLOR, 340, 195, 24);
	m_guiBuilder.addTextBox("+", BUTTON_TEXT_COLOR, 333, 145, 24);
	m_guiBuilder.addTextBox("-", BUTTON_TEXT_COLOR, 333, 240, 24);

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
		case (int)Buttons::NewDevice1:
			m_stateManager->changeState(std::make_unique<NewDeviceControllingSignalMenuState>(m_stateManager));
			return;
		case (int)Buttons::NewDevice2:
			m_stateManager->changeState(std::make_unique<NewDeviceControllingSignalMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
