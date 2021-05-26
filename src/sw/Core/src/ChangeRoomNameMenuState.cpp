#include "ChangeRoomNameMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

ChangeRoomNameMenuState::ChangeRoomNameMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox("Write name:", TEXT_COLOR, 100, 25, 24);
	m_guiBuilder.addTextBox(m_name, TEXT_COLOR, 240, 25, 24);

	m_guiBuilder.addTextBox("Q  W  E  R  T  Y  U  I  O  P", TEXT_COLOR, 250, 130, 20);
	m_guiBuilder.addTextBox("A  S  D  F  G  H  J  K  L", TEXT_COLOR, 240, 180, 20);
	m_guiBuilder.addTextBox("Z  X  C  V  B  N  M", TEXT_COLOR, 240, 230, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 50, 300, 100, 40);
	m_guiBuilder.addTextBox("BACK", BUTTON_TEXT_COLOR, 50, 300, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 430, 300, 100, 40);
	m_guiBuilder.addTextBox("ENTER", BUTTON_TEXT_COLOR, 420, 300, 20);

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void ChangeRoomNameMenuState::update(float deltaTime)
{
}

void ChangeRoomNameMenuState::render()
{
	m_gui.render();
}

void ChangeRoomNameMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Back:
		case (int)Buttons::Enter:
			m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
