#include "GUIBuilder.h"
#include "TextBox.h"
#include "Button.h"

GUIBuilder::GUIBuilder()
{
}

void GUIBuilder::addButton( unsigned xCenter, unsigned yCenter, unsigned width,
		unsigned height, std::string text, ButtonShape shape, Color color,
		unsigned textSize, Color textColor )
{
	m_gui.addButton(std::make_shared<Button>(
			xCenter, yCenter, width, height, text, shape, color, textSize, textColor));
}

void GUIBuilder::addTextBox(unsigned xCenter, unsigned yCenter, std::string text,
		unsigned size, Color color)
{
	m_gui.addTextBox(std::make_shared<TextBox>(xCenter, yCenter, text, size, color));
}

void GUIBuilder::addKeyboard(unsigned xCenter, unsigned yCenter,
		unsigned width, unsigned height, unsigned textSize,
		Color buttonsColor, Color textColor)
{
	//m_gui.addKeyboard();
}

void GUIBuilder::setBackgroundColor(Color color)
{
	m_gui.setBackgroundColor(color);
}

void GUIBuilder::reset()
{
	m_gui = GUI();
}

GUI GUIBuilder::getResult()
{
	return m_gui;
}
