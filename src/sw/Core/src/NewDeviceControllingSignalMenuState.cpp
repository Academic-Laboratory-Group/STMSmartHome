#include "NewDeviceControllingSignalMenuState.h"
#include "RoomSettingsMenuState.h"
#include "StateManager.h"
#include "Utils.h"

NewDeviceControllingSignalMenuState::NewDeviceControllingSignalMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND);

	m_guiBuilder.addTextBox("Kind of controlling signal", BLACK, 240, 40, 24);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 240, 107, 60, 220);
	m_guiBuilder.addTextBox("1/0 binary", BLACK, 245, 107, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 240, 177, 60, 220);
	m_guiBuilder.addTextBox("PWM", BLACK, 235, 177, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 240, 247, 60, 220);
	m_guiBuilder.addTextBox("Impulse", BLACK, 238, 247, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 0, 200, 100, 200);
	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);

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
			m_stateManager->changeState(std::make_shared<RoomSettingsMenuState>(m_stateManager));
			return;
		default:
			// TODO: Temporary when some states are not ready
			m_stateManager->changeState(std::make_shared<RoomSettingsMenuState>(m_stateManager));
			return;
			assert(!("InputResult out of range."));
	}
}
