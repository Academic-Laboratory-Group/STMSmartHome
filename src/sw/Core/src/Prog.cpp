#include "Prog.h"

#include <assert.h>


std::unique_ptr<Prog> Prog::s_progInstance;

Prog::Prog()
{
	assert("Prog creation possible only by getInstance!" && !s_progInstance);
	m_stateManager = std::make_shared<StateManager>();
}

Prog* Prog::getInstance()
{
	if(!s_progInstance)
		s_progInstance = std::make_unique<Prog>();

	return s_progInstance.get();
}

void Prog::update(float)
{
	m_stateManager->update();
}

void Prog::render()
{
	m_stateManager->render();
}

void Prog::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	m_stateManager->processInput(touchAddress);
}
