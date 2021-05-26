#include "StateManager.h"
#include "MainMenuState.h"
#include "ChangeRoomNameMenuState.h"
#include "NewDeviceControllingSignalMenuState.h"
#include "RoomChooseMenuState.h"
#include "RoomSettingsMenuState.h"

StateManager::StateManager()
{
	m_currentState = std::make_unique<MainMenuState>(std::shared_ptr<StateManager>(this));
}

void StateManager::update(float deltaTime)
{
	m_currentState->update(deltaTime);
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
	return{};
}
