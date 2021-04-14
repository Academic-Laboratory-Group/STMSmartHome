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
	
	public:
		void render();
		void processInput();
};

#endif