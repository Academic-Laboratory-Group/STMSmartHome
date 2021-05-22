#include "RoomChooseMenuState.h"
#include "Utils.h"

RoomChooseMenuState::RoomChooseMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addButton(Square, YELLOW, 240, 160, 320, 480);

	m_guiBuilder.addButton(Square, BLUE, 240, 247, 60, 220);
	m_guiBuilder.addTextBox("Add new room", BLACK, 245, 247, 20);

	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);
	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();
}

void RoomChooseMenuState::update(float deltaTime)
{
}

//#include "LCD_Touch.h"
void RoomChooseMenuState::render()
{
	//TP_DrawBoard();
	m_gui->render();
}

void RoomChooseMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	m_gui->processInput(touchAddress);
}

