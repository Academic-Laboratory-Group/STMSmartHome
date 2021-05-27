#ifndef _GUI_BUILDER_H_
#define _GUI_BUILDER_H_

#include "GUI.h"
#include "Utils.h"

#include <memory>

class GUIBuilder
{
	protected:
		GUI m_gui;

	public:
		GUIBuilder();
		~GUIBuilder() = default;

		void addButton(unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned height,
				std::string text,
				ButtonShape shape = Square,
				Color color = BUTTON_BACKGROUND_COLOR,
				unsigned textSize = 20u,
				Color textColor = BUTTON_TEXT_COLOR);

		void addTextBox(unsigned xCenter, unsigned yCenter,
				std::string text, unsigned size = 24u,
				Color color = TEXT_COLOR);

		void addKeyboard(unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned height,
				unsigned textSize = 20u,
				Color buttonsColor = BUTTON_BACKGROUND_COLOR,
				Color textColor = BUTTON_TEXT_COLOR);

		void setBackgroundColor(Color color);

		void reset();
		GUI getResult();
};


#endif
