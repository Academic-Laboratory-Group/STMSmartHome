#include "Prog.h"


std::unique_ptr<Prog> Prog::s_progInstance;

Prog::Prog()
{
	assert(!s_progInstance);
	s_progInstance = std::unique_ptr<Prog>(this);
	m_stateManager = std::make_unique<StateManager>();
}

Prog* Prog::getInstance()
{
	if(!s_progInstance)
		Prog();

	return s_progInstance.get();
}

void Prog::update(float deltaTime)
{
	m_stateManager->update(deltaTime);
}

void Prog::render()
{
	m_stateManager->render();
}

void Prog::processInput()
{
	m_stateManager->processInput();
}
