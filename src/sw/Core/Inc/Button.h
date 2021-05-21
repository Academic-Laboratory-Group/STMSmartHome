#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Utils.h"


class Button
{
	private:
		ButtonShape m_shape;
		Color m_color;
		int m_x;
		int m_y;
		int m_high;
		int m_width;
	
	public:
		Button(ButtonShape shape, Color color, int x, int y, int high, int width);
		void render();
		void processInput();
};


#endif

