#include "Button.h"

#include "LCD_GUI.h"

Button::Button(ButtonShape shape, Color color, unsigned xCenter, unsigned yCenter,
		unsigned width, unsigned height) :
m_shape(shape), m_color(color), m_x(xCenter), m_y(yCenter), m_width(width), m_height(height)
{
}

void Button::render()
{
	if (m_shape == Square)
		GUI_DrawRectangle(m_x - (m_width / 2), m_y - (m_height / 2), m_x + (m_width / 2),
				m_y + (m_height / 2), m_color, DRAW_FULL, DOT_PIXEL_2X2);
	if (m_shape == Circle)
		GUI_DrawCircle(m_x, m_y, m_height / 2, m_color, DRAW_FULL, DOT_PIXEL_2X2);
}

bool Button::processInput(std::pair<unsigned, unsigned> touchAddress) const
{
	return touchAddress.first > m_x - (m_width / 2) && touchAddress.first < m_x + (m_width / 2) &&
			touchAddress.second > m_y - (m_height / 2) && touchAddress.second < m_y + (m_height / 2);
}
