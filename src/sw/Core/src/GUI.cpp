#include "tim.h"

#include "GUI.h"

#include "LCD_GUI.h"

#include <algorithm>


void GUI::render()
{
	HAL_TIM_Base_Stop_IT(&htim13);
	GUI_Clear(m_backgroundColor);

	for_each(m_buttons.begin(), m_buttons.end(),
			[](const auto& button){ button->render(); });
	for_each(m_textBoxes.begin(), m_textBoxes.end(),
			[](const auto& textBoxes){ textBoxes->render(); });
	HAL_TIM_Base_Start_IT(&htim13);
}

int GUI::processInput(std::pair<unsigned, unsigned> touchAddress)
{
	const auto it = std::find_if(m_buttons.begin(), m_buttons.end(),
			[touchAddress](const auto& button){
				return button->processInput(touchAddress); });

	if(it != m_buttons.end())
		return std::distance(m_buttons.begin(), it);

	return -1;
}

void GUI::addButton( std::shared_ptr<Button> button )
{
	m_buttons.emplace_back(std::move(button));
}

void GUI::addTextBox( std::shared_ptr<TextBox> textBox )
{
	m_textBoxes.emplace_back(std::move(textBox));
}

void GUI::setBackgroundColor(Color color)
{
	m_backgroundColor = color;
}

std::string GUI::getButtonText(int idx)
{
	return m_buttons.at(idx)->getText();
}

void GUI::setTextBoxText(int idx, std::string name)
{
	m_textBoxes.at(idx)->setText(name);
}
