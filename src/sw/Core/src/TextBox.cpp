#include "TextBox.h"
#include "LCD_GUI.h"


TextBox::TextBox(unsigned xCenter, unsigned yCenter, std::string text,
		unsigned size, Color color, Color backgroundColor,
		unsigned width, unsigned height) :
		m_text(text), m_size(size), m_color(color), m_backgroundColor(backgroundColor)
{
	if(width != 0u)
	{
		m_left = xCenter - width / 2u;
		m_right = xCenter + width / 2u;
	}
	else
	{
		const auto halfOfTextSize = static_cast<float>(m_text.length()) / 2.0f;

		if(m_size == 16u)
		{
			m_left = xCenter - static_cast<unsigned>(halfOfTextSize * 11.f);
			m_right = xCenter + static_cast<unsigned>(halfOfTextSize * 11.f);
		}
		else if(m_size == 20u)
		{
			m_left = xCenter - static_cast<unsigned>(halfOfTextSize * 14.f);
			m_right = xCenter + static_cast<unsigned>(halfOfTextSize * 14.f);
		}
		else if(m_size == 24u)
		{
			m_left = xCenter - static_cast<unsigned>(halfOfTextSize * 18.f);
			m_right = xCenter + static_cast<unsigned>(halfOfTextSize * 18.f);
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
				m_text.c_str(), &Font16, m_backgroundColor, m_color);
	if(m_size == 20)
		GUI_DisStringInBox_EN(m_left, m_top, m_right, m_bottom,
				m_text.c_str(), &Font20, m_backgroundColor, m_color);
	if(m_size == 24)
		GUI_DisStringInBox_EN(m_left, m_top, m_right, m_bottom,
				m_text.c_str(), &Font24, m_backgroundColor, m_color);
}

std::string TextBox::getText()
{
	return m_text;
}

void TextBox::cleanDisplay()
{
	if(m_size == 16)
		GUI_DrawRectangle(m_left, m_top, m_right,  m_top + 16,
				m_backgroundColor, DRAW_FULL, DOT_PIXEL_2X2);
	if(m_size == 20)
		GUI_DrawRectangle(m_left, m_top, m_right, m_top + 20,
				m_backgroundColor, DRAW_FULL, DOT_PIXEL_2X2);
	if(m_size == 24)
		GUI_DrawRectangle(m_left, m_top, m_right, m_top + 24,
				m_backgroundColor, DRAW_FULL, DOT_PIXEL_2X2);
}

void TextBox::setText(std::string text)
{
	m_text = std::move(text);
	cleanDisplay();
	render();
}
