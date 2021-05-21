#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Utils.h"
#include <string>

class TextBox
{
	private:
		std::string m_text;
		Color m_color;
		int X;
		int Y;
		int Size;
	
	public:
		TextBox(std::string text, Color color, int x, int y, int size);
		void render();
		void processInput();
}	;

#endif

