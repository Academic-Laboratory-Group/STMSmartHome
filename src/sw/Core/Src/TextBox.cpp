#include "TextBox.h"
#include "LCD_GUI.h"

TextBox::TextBox(std::string text, Color color, int x, int y)
{
	m_text = text;
	m_color = color;
	X = x;
	Y = y;
}

void TextBox::render()
{
	GUI_DisString_EN(X, Y, m_text.c_str(), &Font16, FONT_BACKGROUND, m_color);
}

void TextBox::processInput()
{
	
}
