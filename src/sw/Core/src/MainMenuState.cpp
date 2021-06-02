#include "Room.h"
#include "RoomChooseMenuState.h"
#include "MainMenuState.h"
#include "StateManager.h"
#include "Utils.h"

#include <memory>
#include <assert.h>

std::string float2Str(float v);

MainMenuState::MainMenuState(
		std::shared_ptr<StateManager> stateManager) :
		State(stateManager)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox(240, 40, "SmartHome App");

	const auto rooms = m_stateManager->getFlat()->getRooms();

	if (rooms->empty())
	{
		m_guiBuilder.addTextBox(240, 160, "No rooms configured"); // 480x320
	}
	else
	{
		if (rooms->front()->getTemperature() != std::numeric_limits<float>::infinity())
		{
			m_guiBuilder.addTextBox(215, 140, "In " + rooms->front()->getName() + " temperature:", 20u);
			m_guiBuilder.addTextBox(395, 140, float2Str(rooms->front()->getTemperature()), 20u);
			m_guiBuilder.addTextBox(435, 140, "*C", 20u);
		}

		if (rooms->capacity() > 1) // TODO: temporary
		{
			if (rooms->at(1)->getTemperature() != std::numeric_limits<float>::infinity())
			{
				m_guiBuilder.addTextBox(210, 170, "In " + rooms->at(1)->getName() + " temperature:", 20u);
				m_guiBuilder.addTextBox(395, 170, float2Str(rooms->at(1)->getTemperature()), 20u);
				m_guiBuilder.addTextBox(435, 170, "*C", 20u);
			}
		}
	}

	m_guiBuilder.addButton(240, 247, 220, 60, "Adjust settings");

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void MainMenuState::update(float deltaTime)
{
	const auto rooms = m_stateManager->getFlat()->getRooms();
	if (!rooms->empty())
	{
		if (rooms->front()->getTemperature() != std::numeric_limits<float>::infinity())
			m_gui.setTextBoxText(static_cast<int>(TextBoxes::FirstTemperature),
					float2Str(rooms->front()->getTemperature()));

		if (rooms->capacity() > 1)
		{
			if (rooms->at(1)->getTemperature() != std::numeric_limits<float>::infinity())
						m_gui.setTextBoxText(static_cast<int>(TextBoxes::SecondTemperature),
								float2Str(rooms->at(1)->getTemperature()));
		}

	}
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

std::string float2Str(float v)
{
	auto tmp = static_cast<int>(v);
	auto integerStr = std::to_string(tmp);
	tmp = static_cast<int>((v - static_cast<float>(tmp)) * 10.f);
	auto fractionStr = std::to_string(tmp);

	return integerStr + '.' + fractionStr;
}

