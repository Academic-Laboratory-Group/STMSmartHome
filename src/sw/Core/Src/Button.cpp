#include "Button.h"
#include "LCD_GUI.h"

void Button::render()
{
	GUI_DrawRectangle(X - 50, Y - 35, X + 50, Y + 35, m_color, DRAW_FULL, DOT_PIXEL_2X2);
}

void Button::processInput()
{
	
}
