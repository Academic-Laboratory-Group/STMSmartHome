#include "ChangeRoomNameMenuState.h"

#include "RoomChooseMenuState.h"
#include "StateManager.h"
#include "Utils.h"


ChangeRoomNameMenuState::ChangeRoomNameMenuState(
		std::shared_ptr<StateManager> stateManager, std::shared_ptr<Room> room) :
		State(stateManager), m_room(room), m_newName(room->getName())
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox(100, 25, "New name:", 24u, TEXT_COLOR, 200, 50);
	m_guiBuilder.addTextBox(340, 40, m_newName, 24u, TEXT_COLOR, 280, 80);

	m_guiBuilder.addKeyboard(240, 155, 480, 230);
	m_guiBuilder.addButton(240, 300, 200, 40, "_");


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

	const auto inputResultStr = m_gui.getButtonText(inputResult);

	if(inputResultStr == "BACK")
	{
		m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
		return;
	}
	else if(inputResultStr == "ENTER")
	{
		m_room->setName(m_newName);
		m_stateManager->changeState(std::make_unique<RoomChooseMenuState>(m_stateManager));
		return;
	}
	else if(inputResultStr == "_")
	{
		m_newName.push_back(' ');
	}
	else if(inputResultStr == "<-")
	{
		m_newName.pop_back();
	}
	else if(!inputResultStr.empty())
	{
		if(m_newName.length() < 16)
			m_newName.append(inputResultStr);
	}
	else
	{
		assert(!("InputResult out of range."));
	}

	m_gui.setTextBoxText(1, m_newName);
}
