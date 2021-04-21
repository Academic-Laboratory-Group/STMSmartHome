#include "GUI.h"
void GUI::addButton(ButtonShape shape, Color color, int x, int y)
{
	m_buttons.assign(1, Button(shape, color, x, y));
}

void GUI::addTextBox(std::string text, Color color, int x, int y)
{
	m_textboxes.assign(1, TextBox(text, color, x ,y));
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
