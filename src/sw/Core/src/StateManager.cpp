#include "StateManager.h"
#include "MainMenuState.h"
#include "ChangeRoomNameMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "RoomSettingsMenuState.h"

StateManager::StateManager() : m_flat(std::make_shared<Flat>()),
	m_currentState(std::make_unique<MainMenuState>(std::shared_ptr<StateManager>(this)))
{
}

void StateManager::update(float)
{
	m_flat->update();
	m_currentState->update(); // GUI is not using update
}

void StateManager::render()
{
	m_currentState->render();
}

void StateManager::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	m_currentState->processInput(touchAddress);
}

void StateManager::changeState(std::unique_ptr<State> state)
{
	m_currentState = std::move(state);
}

std::shared_ptr<Flat> StateManager::getFlat()
{
	return m_flat;
}
