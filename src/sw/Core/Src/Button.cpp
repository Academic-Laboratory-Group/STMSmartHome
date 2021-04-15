#include "Button.h"
#include "LCD_GUI.h"

Button::Button(ButtonShape shape, Color color, int x, int y)
{
	m_shape = shape;
	m_color = color;
	X = x;
	Y = y;
}
void Button::render()
{
	GUI_DrawRectangle(X - 50, Y - 35, X + 50, Y + 35, m_color, DRAW_FULL, DOT_PIXEL_2X2);
}

void Button::processInput()
{
	
}
