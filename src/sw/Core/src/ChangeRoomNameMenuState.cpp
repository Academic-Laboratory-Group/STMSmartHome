#include "ChangeRoomNameMenuState.h"
#include "Utils.h"

ChangeRoomNameMenuState::ChangeRoomNameMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	m_guiBuilder.addButton(Square, YELLOW, 240, 160, 320, 480);

	m_guiBuilder.addTextBox("Write name:", BLACK, 100, 25, 24);
	m_guiBuilder.addTextBox(m_name, BLACK, 240, 25, 24);

	m_guiBuilder.addTextBox("Q  W  E  R  T  Y  U  I  O  P", BLACK, 250, 130, 20);
	m_guiBuilder.addTextBox("A  S  D  F  G  H  J  K  L", BLACK, 240, 180, 20);
	m_guiBuilder.addTextBox("Z  X  C  V  B  N  M", BLACK, 240, 230, 20);

	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);
	m_guiBuilder.addTextBox("ENTER", BLACK, 420, 300, 20);

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
	m_gui.processInput(touchAddress);
}
