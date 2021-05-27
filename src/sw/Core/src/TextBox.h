#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Utils.h"
#include "Renderable.h"

#include <string>


class TextBox : public Renderable
{
	public:
		TextBox(unsigned xCenter, unsigned yCenter, std::string text,
				unsigned size = 24u, Color color = TEXT_COLOR);
		~TextBox() = default;

		void render();

		std::string getText();

	private:
		unsigned m_x;
		unsigned m_y;
		std::string m_text;
		unsigned m_size;
		Color m_color;
};


#endif
