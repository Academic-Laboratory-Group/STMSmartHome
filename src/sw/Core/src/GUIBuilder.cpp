#include "GUIBuilder.h"

GUIBuilder::GUIBuilder()
{
}

void GUIBuilder::addButton(ButtonShape shape, Color color, int x, int y, int high, int width)
{
	m_gui.addButton(shape, color, x, y, high, width);
}

void GUIBuilder::addTextBox(std::string text, Color color, int x, int y, int size)
{
	m_gui.addTextBox(text, color, x, y, size);
}

void GUIBuilder::setBackgroundColor(Color color)
{
	m_gui.setBackgroundColor(color);
}

void GUIBuilder::addKeyboard()
{
	
}

void GUIBuilder::reset()
{
	m_gui = GUI();
}

GUI GUIBuilder::getResult()
{
	return m_gui;
}
