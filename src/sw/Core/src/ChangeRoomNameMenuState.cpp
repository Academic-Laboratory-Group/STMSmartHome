#include "ChangeRoomNameMenuState.h"
#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"

ChangeRoomNameMenuState::ChangeRoomNameMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox(100, 25, "Write name:");
	m_guiBuilder.addTextBox(240, 25, m_name);

	m_guiBuilder.addKeyboard(240, 155, 480, 230);

	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");
	m_guiBuilder.addButton(430, 300, 100, 40, "ENTER");

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
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Back:
		case (int)Buttons::Enter:
			m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
