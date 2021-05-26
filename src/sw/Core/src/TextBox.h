#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Utils.h"
#include "Renderable.h"

#include <string>


class TextBox : public Renderable
{
	public:
		TextBox(std::string text, Color color, unsigned xCenter, unsigned yCenter, unsigned size);
		void render();

	private:
		std::string m_text;
		Color m_color;
		unsigned m_x;
		unsigned m_y;
		unsigned m_size;
};


#endif
