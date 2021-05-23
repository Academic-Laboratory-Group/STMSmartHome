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

		void addButton(ButtonShape shape, Color color, int x, int y, int high, int width);
		void addTextBox(std::string text, Color color, int x, int y, int size);
		void addKeyboard(void);
		void setBackgroundColor(Color color);
		void reset();
		GUI getResult();
};


#endif
