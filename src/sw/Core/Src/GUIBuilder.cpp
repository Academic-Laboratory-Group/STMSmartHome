#include "GUIBuilder.h"

GUIBuilder::GUIBuilder()
{
	m_gui = new GUI();
}

GUIBuilder::~GUIBuilder()
{
	delete m_gui;
}

void GUIBuilder::addButton(ButtonShape shape, Color color, int x, int y)
{
	m_gui->addButton(shape, color, x, y);
}

void GUIBuilder::addTextBox(std::string text, Color color, int x, int y)
{
	m_gui->addTextBox(text, color, x, y);
}

void GUIBuilder::addKeyboard()
{
	
}

void GUIBuilder::reset()
{
	delete m_gui;
	m_gui = new GUI();
}

GUI* GUIBuilder::getResult()
{
	return m_gui;
}
