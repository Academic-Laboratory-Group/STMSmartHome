#include "TextBox.h"
#include "LCD_GUI.h"

TextBox::TextBox(unsigned xCenter, unsigned yCenter, std::string text,
		unsigned size, Color color) :
		m_x(xCenter), m_y(yCenter), m_text(text), m_size(size), m_color(color)
{
}

void TextBox::render()
{
	if(m_size == 16)
		GUI_DisString_EN(m_x - ((m_text.length()/2) * 11), m_y - 6, m_text.c_str(),
				&Font16, FONT_BACKGROUND, m_color);
	if(m_size == 20)
		GUI_DisString_EN(m_x - ((m_text.length()/2) * 15) + 5, m_y - 8, m_text.c_str(),
				&Font20, FONT_BACKGROUND, m_color);
	if(m_size == 24)
		GUI_DisString_EN(m_x - ((m_text.length()/2) * 17) - 5, m_y - 10, m_text.c_str(),
				&Font24, FONT_BACKGROUND, m_color);
}

std::string TextBox::getText()
{
 return m_text;
}
