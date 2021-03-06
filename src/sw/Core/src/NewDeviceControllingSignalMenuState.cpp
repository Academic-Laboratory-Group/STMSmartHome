#include "NewDeviceControllingSignalMenuState.h"
#include "RoomSettingsMenuState.h"
#include "StateManager.h"
#include "Utils.h"

NewDeviceControllingSignalMenuState::NewDeviceControllingSignalMenuState(
		std::shared_ptr<StateManager> stateManager, std::shared_ptr<Room> room) :
		State(stateManager), m_room(room)
{
	// make new
	m_guiBuilder.setBackgroundColor(BACKGROUND_COLOR);

	m_guiBuilder.addTextBox(240, 40, "Kind of controlling signal", 24);

	m_guiBuilder.addButton(240, 107, 220, 60, "1/0 binary");
	m_guiBuilder.addButton(240, 177, 220, 60, "PWM");
	m_guiBuilder.addButton(50, 300, 100, 40, "BACK");

	// set pointer to new GUI
	m_gui = m_guiBuilder.getResult();

	// temporary
	render();
}

void NewDeviceControllingSignalMenuState::update(float deltaTime)
{
}

void NewDeviceControllingSignalMenuState::render()
{
	m_gui.render();
}

void NewDeviceControllingSignalMenuState::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto inputResult = m_gui.processInput(touchAddress);

	if (inputResult < 0)
		return;

	const auto inputResultStr = m_gui.getButtonText(inputResult);

	if (inputResultStr == "BACK")
	{
		m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager, m_room));
		return;
	}
	else if(inputResultStr == "1/0 binary")
	{
		//m_room->setControllerValue(controllerId, value)
		m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager, m_room));
		return;
	}
	else if(inputResultStr == "PWM")
	{
		//m_room->getSensor()->setSensorId(Temperature1);
		m_stateManager->changeState(std::make_unique<RoomSettingsMenuState>(m_stateManager, m_room));
		return;
	}
	else
	{
		assert(!("InputResult out of range."));
	}
}
