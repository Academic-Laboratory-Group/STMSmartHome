#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "TextBox.h"
#include "Utils.h"
#include "Renderable.h"

#include <utility>
#include <string>
#include <memory>


class Button : public Renderable
{
	public:
		Button( unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned height,
				const std::string text,
				ButtonShape shape = Square,
				Color color = BUTTON_BACKGROUND_COLOR,
				unsigned textSize = 20u,
				Color textColor = BUTTON_TEXT_COLOR );

		void render();
		bool processInput(std::pair<unsigned, unsigned> touchAddress) const;

		std:: string getText() const;

	private:
		unsigned m_x;
		unsigned m_y;
		unsigned m_width;
		unsigned m_height;
		ButtonShape m_shape;
		Color m_color;
		std::unique_ptr<TextBox> m_textBox;
};

#endif
