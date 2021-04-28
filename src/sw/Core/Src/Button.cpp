#include "Button.h"
#include "LCD_GUI.h"

Button::Button(ButtonShape shape, Color color, int x, int y, int high, int width)
{
	m_shape = shape;
	m_color = color;
	X = x;
	Y = y;
	High = high / 2;
	Width = width / 2;
}
void Button::render()
{
	GUI_DrawRectangle(X - Width, Y - High, X + Width, Y + High, m_color, DRAW_EMPTY, DOT_PIXEL_2X2);
}

void Button::processInput()
{
	
}
