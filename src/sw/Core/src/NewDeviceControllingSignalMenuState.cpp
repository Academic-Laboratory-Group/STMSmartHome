#include "NewDeviceControllingSignalMenuState.h"
#include "RoomSettingsMenuState.h"
#include "StateManager.h"
#include "Utils.h"

NewDeviceControllingSignalMenuState::NewDeviceControllingSignalMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox("Kind of controlling signal", TEXT_COLOR, 240, 40, 24);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 240, 107, 220, 60);
	m_guiBuilder.addTextBox("1/0 binary", BUTTON_TEXT_COLOR, 245, 107, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 240, 177, 220, 60);
	m_guiBuilder.addTextBox("PWM", BUTTON_TEXT_COLOR, 235, 177, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 240, 247, 220, 60);
	m_guiBuilder.addTextBox("Impulse", BUTTON_TEXT_COLOR, 238, 247, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 0, 200, 200, 100);
	m_guiBuilder.addTextBox("BACK", BUTTON_TEXT_COLOR, 50, 300, 20);

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void NewDeviceControllingSignalMenuState::update(float deltaTime)
{
}

void NewDeviceControllingSignalMenuState::render()
{
	m_gui.render();
}

void NewDeviceControllingSignalMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Back:
			m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager));
			return;
		default:
			// TODO: Temporary when some states are not ready
			m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager));
			return;
			assert(!("InputResult out of range."));
	}
}
