#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <memory>
#include <assert.h>


MainMenuState::MainMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox("SmartHome App", TEXT_COLOR, 240, 40, 24);

	m_guiBuilder.addTextBox("FirstRoom temperature:", TEXT_COLOR, 215, 140, 20);
	m_guiBuilder.addTextBox("23*C", TEXT_COLOR, 395, 140, 20);

	m_guiBuilder.addTextBox("SecondRoom temperature:", TEXT_COLOR, 210, 170, 20);
	m_guiBuilder.addTextBox("23*C", TEXT_COLOR, 405, 170, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 240, 247, 220, 60);
	m_guiBuilder.addTextBox("Adjust settings", BUTTON_TEXT_COLOR, 240, 247, 20);

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void MainMenuState::update(float deltaTime)
{
}

void MainMenuState::render()
{
	m_gui.render();
}

void MainMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Adjust:
			m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
