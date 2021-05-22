#include "GUI.h"

#include "LCD_GUI.h"

#include <algorithm>


void GUI::render()
{
	GUI_Clear(m_backgroundColor);

	for_each(m_buttons.begin(), m_buttons.end(),
			[](std::shared_ptr<Button> button){ button->render(); });
	for_each(m_textboxes.begin(), m_textboxes.end(),
			[](std::shared_ptr<TextBox> textboxes){ textboxes->render(); });
}

int GUI::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto it = std::find_if(m_buttons.begin(), m_buttons.end(),
			[touchAddress](std::shared_ptr<Button> button){ return button->processInput(touchAddress); });

	if(it != m_buttons.end())
		return std::distance(m_buttons.begin(), it);

	return -1;
}

void GUI::addButton(ButtonShape shape, Color color, unsigned x, unsigned y,
		unsigned high, unsigned width)
{
	m_buttons.push_back(std::make_unique<Button>(shape, color, x, y, high, width));
}

void GUI::addTextBox(std::string text, Color color, unsigned x, unsigned y, unsigned size)
{
	m_textboxes.push_back(std::make_unique<TextBox>(text, color, x ,y, size));
}

void GUI::setBackgroundColor(Color color)
{
	m_backgroundColor = color;
}

