#include "MainMenuState.h"
#include "Utils.h"

MainMenuState::MainMenuState(StateManager* stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addButton(Square, BLUE, 100, 50);
	
	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();
}

MainMenuState::~MainMenuState()
{
	// delete old GUI
	if (m_gui != NULL)
	{
		delete m_gui;
	}
}

void MainMenuState::update(float deltaTime)
{
}

//#include "LCD_Touch.h"
void MainMenuState::render()
{
	//TP_DrawBoard();
	m_gui->render();
}

void MainMenuState::processInput()
{
}
