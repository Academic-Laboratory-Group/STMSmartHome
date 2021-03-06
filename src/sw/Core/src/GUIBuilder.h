#ifndef _GUI_BUILDER_H_
#define _GUI_BUILDER_H_

#include "GUI.h"
#include "Utils.h"

#include <memory>
#include <string>

class GUIBuilder
{
	protected:
		GUI m_gui;

	public:
		GUIBuilder();
		~GUIBuilder() = default;

		void addButton(unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned height,
				const std::string text,
				ButtonShape shape = ButtonShape::Square,
				Color color = BUTTON_BACKGROUND_COLOR,
				unsigned textSize = 20u,
				Color textColor = BUTTON_TEXT_COLOR);

		void addTextBox(unsigned xCenter, unsigned yCenter,
				std::string text, unsigned size = 24u,
				Color color = TEXT_COLOR,
				Color backgroundColor = BACKGROUND_COLOR,
				unsigned width = 0u, unsigned height = 0u);

		void addKeyboard(unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned height,
				unsigned textSize = 20u,
				Color buttonsColor = BUTTON_BACKGROUND_COLOR,
				Color textColor = BUTTON_TEXT_COLOR);

		void addCircle(int xCenter, int yCenter, int radius,
				Color color = BUTTON_BACKGROUND_COLOR);

		void setBackgroundColor(Color color);

		void reset();
		GUI getResult();
};


#endif
