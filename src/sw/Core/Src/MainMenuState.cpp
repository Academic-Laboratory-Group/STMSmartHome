#include "MainMenuState.h"
#include "Utils.h"

MainMenuState::MainMenuState(StateManager* stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addButton(Square, YELLOW, 240, 160, 320, 480);

	m_guiBuilder.addTextBox("SmartHome App", BLACK, 240, 40, 24);

	m_guiBuilder.addTextBox("FirstRoom temperature:", BLACK, 215, 140, 20);
	m_guiBuilder.addTextBox("23*C", BLACK, 395, 140, 20);

	m_guiBuilder.addTextBox("SecondRoom temperature:", BLACK, 210, 170, 20);
	m_guiBuilder.addTextBox("23*C", BLACK, 405, 170, 20);

	m_guiBuilder.addButton(Square, BLUE, 240, 247, 60, 220);
	m_guiBuilder.addTextBox("Adjust settings", BLACK, 240, 247, 20);
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
