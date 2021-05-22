#include "RoomSettingsMenuState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <memory>


MainMenuState::MainMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(YELLOW);

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

void MainMenuState::update(float deltaTime)
{
}

void MainMenuState::render()
{
	m_gui->render();
}

void MainMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	auto manager = m_stateManager.lock();
	const auto inputResult = m_gui->processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Adjust:
			manager->changeState(std::make_shared<RoomSettingsMenuState>(manager));
			return;
		default:
			assert(!"Out of possibilities");
	}
}
