#include "Prog.h"

#include <assert.h>


std::unique_ptr<Prog> Prog::s_progInstance;

Prog::Prog()
{
	assert("Prog creation possible only by getInstance!" && !s_progInstance);
	m_stateManager = std::make_unique<StateManager>();
}

Prog* Prog::getInstance()
{
	if(!s_progInstance)
		s_progInstance = std::make_unique<Prog>();

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
