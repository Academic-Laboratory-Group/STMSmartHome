/*
 * NewDeviceControllingSignalMenuState.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#include "NewDeviceControllingSignalMenuState.h"
#include "Utils.h"

NewDeviceControllingSignalMenuState::NewDeviceControllingSignalMenuState(StateManager* stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addButton(Square, YELLOW, 240, 160, 320, 480);

	m_guiBuilder.addTextBox("Kind of controlling signal", BLACK, 240, 40, 24);

	m_guiBuilder.addButton(Square, BLUE, 240, 107, 60, 220);
	m_guiBuilder.addTextBox("1/0 binary", BLACK, 245, 107, 20);

	m_guiBuilder.addButton(Square, BLUE, 240, 177, 60, 220);
	m_guiBuilder.addTextBox("PWM", BLACK, 235, 177, 20);

	m_guiBuilder.addButton(Square, BLUE, 240, 247, 60, 220);
	m_guiBuilder.addTextBox("Impulse", BLACK, 238, 247, 20);

	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);
	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();
}

NewDeviceControllingSignalMenuState::~NewDeviceControllingSignalMenuState()
{
	// delete old GUI
	if (m_gui != NULL)
	{
		delete m_gui;
	}
}

void NewDeviceControllingSignalMenuState::update(float deltaTime)
{
}

//#include "LCD_Touch.h"
void NewDeviceControllingSignalMenuState::render()
{
	//TP_DrawBoard();
	m_gui->render();
}

void NewDeviceControllingSignalMenuState::processInput()
{
}
