#include "TextBox.h"
#include "LCD_GUI.h"

TextBox::TextBox(std::string text, Color color, int x, int y, int size)
{
	m_text = text;
	m_color = color;
	X = x;
	Y = y;
	Size = size;

}

void TextBox::render()
{
	if(Size == 16)
		GUI_DisString_EN(X - ((m_text.length()/2) * 11), Y - 6, m_text.c_str(), &Font16, FONT_BACKGROUND, m_color);
	if(Size == 20)
		GUI_DisString_EN(X - ((m_text.length()/2) * 15), Y - 8, m_text.c_str(), &Font20, FONT_BACKGROUND, m_color);
	if(Size == 24)
		GUI_DisString_EN(X - ((m_text.length()/2) * 18.5), Y - 10, m_text.c_str(), &Font24, FONT_BACKGROUND, m_color);
}

void TextBox::processInput()
{
	
}
