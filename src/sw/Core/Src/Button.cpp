#include "Button.h"
#include "LCD_GUI.h"

Button::Button(ButtonShape shape, Color color, int x, int y, int high, int width)
{
	m_shape = shape;
	m_color = color;
	m_x = x;
	m_y = y;
	m_high = high / 2;
	m_width = width / 2;
}
void Button::render()
{
	if (m_shape == Square)
		GUI_DrawRectangle(m_x - m_width, m_y - m_high, m_x + m_width, m_y + m_high, m_color, DRAW_FULL, DOT_PIXEL_2X2);
	if (m_shape == Circle)
		GUI_DrawCircle(m_x, m_y, m_high, m_color, DRAW_FULL, DOT_PIXEL_2X2);
}

void Button::processInput()
{
	
}
