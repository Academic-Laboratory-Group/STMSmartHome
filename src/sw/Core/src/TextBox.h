#ifndef _TEXTBOX_H_
#define _TEXTBOX_H_

#include "Utils.h"
#include "Renderable.h"

#include <string>


class TextBox : public Renderable
{
	public:
		TextBox(unsigned xCenter, unsigned yCenter, std::string text,
				unsigned size = 24u, Color color = TEXT_COLOR,
				Color backgroundColor = BACKGROUND_COLOR,
				unsigned width = 0u, unsigned height = 0u);
		~TextBox() = default;

		void render();

		std::string getText();
		void setText(std::string text);

	private:
		void cleanDisplay();

		unsigned m_left{};
		unsigned m_bottom{};
		unsigned m_top{};
		unsigned m_right{};
		std::string m_text;
		unsigned m_size;
		Color m_color;
		Color m_backgroundColor;
};


#endif
