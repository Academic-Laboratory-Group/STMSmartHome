#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <memory>
#include <assert.h>


MainMenuState::MainMenuState(
		std::shared_ptr<StateManager> stateManager) :
		State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox(240, 40, "SmartHome App");

	m_guiBuilder.addTextBox(215, 140, "FirstRoom temperature:", 20u);
	m_guiBuilder.addTextBox(395, 140, "23*C", 20u);

	m_guiBuilder.addTextBox(210, 170, "SecondRoom temperature:", 20u);
	m_guiBuilder.addTextBox(405, 170, "23*C", 20u);

	m_guiBuilder.addButton(240, 247, 220, 60, "Adjust settings");

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
