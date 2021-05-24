#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "RoomSettingsMenuState.h"
#include "ChangeRoomNameMenuState.h"
#include "StateManager.h"
#include "Utils.h"

RoomChooseMenuState::RoomChooseMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 50, 300, 40, 100);
	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 100, 50, 40, 110);
	m_guiBuilder.addTextBox("Room 1", BLACK, 100, 50, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 240, 247, 50, 200);
	m_guiBuilder.addTextBox("Add new room", BLACK, 240, 247, 20);

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void RoomChooseMenuState::update(float deltaTime)
{
}

void RoomChooseMenuState::render()
{
	m_gui.render();
}

void RoomChooseMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Back:
			m_stateManager->changeState(std::make_shared<MainMenuState>(m_stateManager));
			return;
		case (int)Buttons::Room:
			m_stateManager->changeState(std::make_shared<RoomSettingsMenuState>(m_stateManager));
			return;
		case (int)Buttons::NewRoom:
			m_stateManager->changeState(std::make_shared<ChangeRoomNameMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
