#include "GUIBuilder.h"

GUIBuilder::GUIBuilder()
{
	m_gui = new GUI();
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
