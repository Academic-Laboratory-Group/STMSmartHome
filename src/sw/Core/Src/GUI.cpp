#include "GUI.h"
void GUI::addButton()
{
	
	m_buttons.push_back(Button());
}

void GUI::addTextBox()
{
	
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
