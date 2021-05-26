#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "RoomSettingsMenuState.h"
#include "ChangeRoomNameMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <assert.h>
#include <algorithm>
#include <math.h>


RoomChooseMenuState::RoomChooseMenuState(std::shared_ptr<StateManager> stateManager) : State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 50, 300, 100, 40);
	m_guiBuilder.addTextBox("BACK", BUTTON_TEXT_COLOR, 50, 300, 20);

	const auto rooms = m_stateManager->getFlat()->getRooms();
	if (rooms.empty())
	{
		m_guiBuilder.addTextBox("No rooms configured", BLACK, 240, 160, 24); // 480x320
	}
	else
	{
		/*
		const auto roomsSize = static_cast<float>(rooms.size());
		constexpr unsigned maxRowSize = 3;
		constexpr unsigned maxColSize = 3;
		constexpr std::pair<unsigned, unsigned> boxSize(480, 220);
		constexpr unsigned maxColSize = 3;

		assert(!(maxRowSize * maxColSize > roomsSize));

		const auto rowColAmount = roundf(sqrtf(roomsSize));
		const auto lastRowSize = remainderf(roomsSize, maxRowSize);

		int idx;
		for(const auto & room : rooms)
		{
			const auto x =
			m_guiBuilder.addButton(Square, BUTTON_BACKGROUND,
					(boxSize.first / (2 * rowColAmount)),
					(boxSize.second / (2 * rowColAmount)), 40, 110);
			m_guiBuilder.addTextBox(room->getName(), BLACK, 100, 50, 20);
		}*/
		unsigned idx{};
		unsigned idy{};
		for (const auto& room : rooms)
		{
			m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, idx, idy, 50, 110);
			// m_guiBuilder.addTextBox(room->getName(), BLACK, idx, idy, 20); // TODO
		}
	}
	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND, 100, 50, 40, 110);
	m_guiBuilder.addTextBox("Room 1", BLACK, 100, 50, 20);

	m_guiBuilder.addButton(Square, BUTTON_BACKGROUND_COLOR, 240, 247, 200, 50);
	m_guiBuilder.addTextBox("Add new room", BUTTON_TEXT_COLOR, 240, 247, 20);

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
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	switch(inputResult)
	{
		case (int)Buttons::Back:
			m_stateManager->changeState(std::make_unique<MainMenuState>(m_stateManager));
			return;
		case (int)Buttons::Room:
			m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager));
			return;
		case (int)Buttons::NewRoom:
			m_stateManager->changeState(std::make_unique<ChangeRoomNameMenuState>(m_stateManager));
			return;
		default:
			assert(!("InputResult out of range."));
	}
}
