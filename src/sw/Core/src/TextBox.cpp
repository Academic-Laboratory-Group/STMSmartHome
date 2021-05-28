#include "TextBox.h"
#include "LCD_GUI.h"

TextBox::TextBox(unsigned xCenter, unsigned yCenter, std::string text,
		unsigned size, Color color, unsigned width, unsigned height) :
		m_text(text), m_size(size), m_color(color)
{
	if(width != 0u)
	{
		m_left = xCenter - width / 2u;
		m_right = xCenter + width / 2u;
	}
	else
	{
		if(m_size == 16u)
		{
			m_left = xCenter - ((m_text.length()/2u) * 11u);
			m_right = xCenter + ((m_text.length()/2u) * 11u);
		}
		else if(m_size == 20u)
		{
			m_left = xCenter - ((m_text.length()/2u) * 15u) + 5u;
			m_right = xCenter + ((m_text.length()/2u) * 15u) - 5u;
		}
		else if(m_size == 24u)
		{
			m_left = xCenter - ((m_text.length()/2u) * 17u) - 5u;
			m_right = xCenter + ((m_text.length()/2u) * 17u) + 5u;
		}
	}

	if(height != 0u)
	{
		m_bottom = yCenter + height / 2u;
		m_top = yCenter - height / 2u;
	}
	else
	{
		m_bottom = yCenter + m_size / 2u + 1;
		m_top = yCenter - m_size / 2u - 1;
	}
}

void TextBox::render()
{
	if(m_size == 16)
		GUI_DisStringInBox_EN(m_left, m_top, m_right, m_bottom,
				m_text.c_str(), &Font16, FONT_BACKGROUND, m_color);
	if(m_size == 20)
		GUI_DisStringInBox_EN(m_left, m_top, m_right, m_bottom,
				m_text.c_str(), &Font20, FONT_BACKGROUND, m_color);
	if(m_size == 24)
		GUI_DisStringInBox_EN(m_left, m_top, m_right, m_bottom,
				m_text.c_str(), &Font24, FONT_BACKGROUND, m_color);
}

std::string TextBox::getText()
{
	return m_text;
}

void TextBox::cleanDisplay()
{
	if(m_size == 16)
		GUI_DrawRectangle(m_left, m_bottom, m_right, m_top,
				FONT_BACKGROUND, DRAW_FULL, DOT_PIXEL_2X2);
	if(m_size == 20)
		GUI_DrawRectangle(m_left, m_bottom, m_right, m_top,
				FONT_BACKGROUND, DRAW_FULL, DOT_PIXEL_2X2);
	if(m_size == 24)
		GUI_DrawRectangle(m_left, m_bottom, m_right, m_top,
				FONT_BACKGROUND, DRAW_FULL, DOT_PIXEL_2X2);
}

void TextBox::setText(std::string text)
{
	m_text = std::move(text);
	cleanDisplay();
	render();
}
