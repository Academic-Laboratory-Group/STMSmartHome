#include "GUI.h"

void GUI::addButton(ButtonShape shape, Color color, int x, int y, int high, int width)
{
	
	m_buttons.push_back(Button(shape, color, x, y, high, width));
}

void GUI::addTextBox(std::string text, Color color, int x, int y, int size)
{
	m_textboxes.push_back(TextBox(text, color, x ,y, size));
}

void GUI::render()
{
	for (int i = 0; i < m_buttons.size(); ++i)
		m_buttons[i].render();

	for (int i = 0; i < m_textboxes.size(); ++i)
		m_textboxes[i].render();
}

void GUI::processInput()
{
	
}
