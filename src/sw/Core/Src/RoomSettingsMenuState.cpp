/*
 * RoomSettingsMenuState.cpp
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#include "RoomSettingsMenuState.h"
#include "Utils.h"

RoomSettingsMenuState::RoomSettingsMenuState(StateManager* stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.addButton(Square, YELLOW, 240, 160, 320, 480);

	m_guiBuilder.addTextBox(m_name, BLACK, 230, 40, 24);

	m_guiBuilder.addTextBox("Temperature:", BLACK, 115, 85, 20);
	m_guiBuilder.addTextBox(m_temperature, BLACK, 220, 85, 20);
	m_guiBuilder.addTextBox("*C" ,BLACK, 270, 85, 20);

	m_guiBuilder.addButton(Circle, BLUE, 140, 195, 150, 150);
	m_guiBuilder.addTextBox("Light", BLACK, 135, 195, 24);
	m_guiBuilder.addTextBox("+", RED, 133, 145, 24);
	m_guiBuilder.addTextBox("-", BLACK, 133, 240, 24);

	m_guiBuilder.addButton(Circle, BLUE, 340, 195, 150, 150);
	m_guiBuilder.addTextBox("Heater", BLACK, 340, 195, 24);
	m_guiBuilder.addTextBox("+", RED, 333, 145, 24);
	m_guiBuilder.addTextBox("-", BLACK, 333, 240, 24);

	m_guiBuilder.addTextBox("BACK", BLACK, 50, 300, 20);
	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();
}

RoomSettingsMenuState::~RoomSettingsMenuState()
{
	// delete old GUI
	if (m_gui != NULL)
	{
		delete m_gui;
	}
}

void RoomSettingsMenuState::update(float deltaTime)
{
}

//#include "LCD_Touch.h"
void RoomSettingsMenuState::render()
{
	//TP_DrawBoard();
	m_gui->render();
}

void RoomSettingsMenuState::processInput()
{
}



