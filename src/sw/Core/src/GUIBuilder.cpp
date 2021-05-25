#include "GUIBuilder.h"

GUIBuilder::GUIBuilder()
{
}

void GUIBuilder::addButton(ButtonShape shape, Color color, unsigned xCenter,
		unsigned yCenter, unsigned width, unsigned high)
{
	m_gui.addButton(shape, color, xCenter, yCenter, width, high);
}

void GUIBuilder::addTextBox(std::string text, Color color, unsigned xCenter,
		unsigned yCenter, unsigned size)
{
	m_gui.addTextBox(text, color, xCenter, yCenter, size);
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
