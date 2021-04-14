#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include <iostream>
#include "Utils.h"
#include <string>

class TextBox
{
	private:
		Color m_color;
		//XYPair m_size;
		//XYPair m_displayAddress;
	
		std::string m_text;
	
	public:
		void render();
		void processInput();
}	;

#endif