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

void StateManager::processInput()
{
	m_currentState->processInput();
}
