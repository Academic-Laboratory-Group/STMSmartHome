#include "Prog.h"

Prog::Prog() : m_stateManager()
{
}

void Prog::update(float deltaTime)
{
	m_stateManager.update(deltaTime);
}

void Prog::render()
{
	m_stateManager.render();
}

void Prog::processInput()
{
	m_stateManager.processInput();
}
