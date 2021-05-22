#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "Utils.h"
#include "Renderable.h"

#include <utility>

class Button : public Renderable
{
	public:
		Button(ButtonShape shape, Color color, unsigned x, unsigned y, unsigned height, unsigned width);

		void render();
		bool processInput(std::pair<unsigned, unsigned> touchAddress) const;

	private:
		ButtonShape m_shape;
		Color m_color;
		unsigned m_x;
		unsigned m_y;
		unsigned m_height;
		unsigned m_width;
};

#endif
