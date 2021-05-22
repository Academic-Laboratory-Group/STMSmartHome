#include "GUIBuilder.h"

GUIBuilder::GUIBuilder() : m_gui(std::make_unique<GUI>())
{
}

void GUIBuilder::addButton(ButtonShape shape, Color color, int x, int y, int high, int width)
{
	m_gui->addButton(shape, color, x, y, high, width);
}

void GUIBuilder::addTextBox(std::string text, Color color, int x, int y, int size)
{
	m_gui->addTextBox(text, color, x, y, size);
}

void GUIBuilder::setBackgroundColor(Color color)
{
	m_gui->setBackgroundColor(color);
}

void GUIBuilder::addKeyboard()
{
	
}

void GUIBuilder::reset()
{
	m_gui.reset();
	m_gui = std::make_unique<GUI>();
}

std::unique_ptr<GUI> GUIBuilder::getResult()
{
	return std::move(m_gui);
}
