#include "GUI.h"
void GUI::addButton(ButtonShape shape, Color color, int x, int y)
{
	m_buttons.push_back(Button(shape, color, x, y));
}

void GUI::addTextBox(char *text, Color color, int x, int y)
{
	m_textboxes.push_back(TextBox(text, color, x ,y));
}

void GUI::render()
{
	if (m_buttons.size() > 0)
	{
		for (int i = 0; i < m_buttons.size(); i++)
			m_buttons[i].render();
	}
	
	if (m_textboxes.size() > 0)
	{
		for (int i = 0; i < m_textboxes.size(); i++)
			m_textboxes[i].render();
	}
}

void GUI::processInput()
{
	
}
