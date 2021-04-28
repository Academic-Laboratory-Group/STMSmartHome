#include "MainMenuState.h"
#include "Utils.h"

MainMenuState::MainMenuState(StateManager* stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addTextBox("SmartHome App", BLACK, 240, 40, 24);
	m_guiBuilder.addTextBox("FirstRoom", BLACK, 180, 140, 20);
	//m_guiBuilder.addTextBox("temperature", BLACK, 180, 140, 20);
	m_guiBuilder.addTextBox("23*C", BLACK, 370, 160, 20);
	m_guiBuilder.addTextBox("SecondRoom", BLACK, 240, 120, 20);
	//m_guiBuilder.addTextBox("23*C", BLACK, 380, 120, 20);
	m_guiBuilder.addButton(Square, RED, 240, 247, 60, 220);
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
