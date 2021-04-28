#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Utils.h"


class Button
{
	private:
		ButtonShape m_shape;
		Color m_color;
		int X;
		int Y;
		int High;
		int Width;
	
	public:
		Button(ButtonShape shape, Color color, int x, int y, int high, int width);
		void render();
		void processInput();
};


#endif

