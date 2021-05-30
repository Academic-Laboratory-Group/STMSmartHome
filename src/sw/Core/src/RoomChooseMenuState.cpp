#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "RoomSettingsMenuState.h"
#include "ChangeRoomNameMenuState.h"
#include "Flat.h"
#include "Room.h"
#include "StateManager.h"
#include "Utils.h"

#include <assert.h>
#include <algorithm>
#include <math.h>
#include <memory>
#include <iterator>



RoomChooseMenuState::RoomChooseMenuState(
		std::shared_ptr<StateManager> stateManager) :
		State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");

	const auto rooms = m_stateManager->getFlat()->getRooms();
	if (rooms->empty())
	{
		m_guiBuilder.addTextBox(240, 160, "No rooms configured"); // 480x320
	}
	else
	{
		m_guiBuilder.addTextBox(110, 25, "Choose room:", 24u, TEXT_COLOR, 220, 50);

		unsigned idx = 20u;
		unsigned idy = 70u;
		unsigned free_place = 480u;
		for (const auto& room : *rooms.get())
		{
			if (room->getName().length() * 14 < free_place )
				idx += (room->getName().length() * 14)/2u;
			else
			{
				idy += 60u;
				idx = (room->getName().length() * 14)/2u + 20;
				free_place = 460u;
			}
			free_place -= room->getName().length() * 14;
			m_guiBuilder.addButton( idx, idy, room->getName().length() * 14 + 20, 50,
					room->getName());
			idx += ((room->getName().length() * 14 + 20)/2u) + 20u;
		}
	}

	m_guiBuilder.addButton(240, 247, 200, 50, "Add new room");

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void RoomChooseMenuState::update(float deltaTime)
{
}

void RoomChooseMenuState::render()
{
	m_gui.render();
}

void RoomChooseMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto rooms = m_stateManager->getFlat()->getRooms();

	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	const auto inputResultStr = m_gui.getButtonText(inputResult);

	if(inputResultStr == "BACK")
	{
		m_stateManager->changeState(std::make_unique<MainMenuState>(m_stateManager));
		return;
	}
	else if(inputResultStr == "Add new room")
	{
		m_stateManager->getFlat()->addRoom(std::make_shared<Room>());
		m_stateManager->changeState(std::make_unique<ChangeRoomNameMenuState>(
				m_stateManager,m_stateManager->getFlat()->getRooms().get()->back()));

		return;
	}
	else
	{
		const auto result = std::find_if(rooms->begin(),
					rooms->end(),[inputResultStr](const auto room){
						return room->getName() == inputResultStr;});

		if(result != rooms->end())
		{
			m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(
					m_stateManager, *result));
			return;
		}
		else
		{
			assert(!("InputResult out of range."));
		}

	}

}
