#include "Prog.h"
#include "LCD_Touch.h"

Prog::Prog() : m_stateManager()
{
}

Prog::~Prog()
{
	delete m_instance;
}

Prog* Prog::m_instance;

Prog* Prog::getInstance()
{
	if(m_instance == NULL)
	{
		m_instance = new Prog();
	}
	return m_instance;
}

void Prog::update(float deltaTime)
{
	m_stateManager.update(deltaTime);
}

void Prog::render()
{
	//TP_DrawBoard();
	//m_stateManager.render();
}

void Prog::processInput()
{
	m_stateManager.processInput();
}
