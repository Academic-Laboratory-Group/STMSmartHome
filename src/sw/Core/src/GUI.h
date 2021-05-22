#ifndef _GUI_H_
#define _GUI_H_

#include <vector>
#include "Button.h"
#include "TextBox.h"
#include "Utils.h"

class GUI
{
	private:
		std::vector <Button> m_buttons;
		std::vector <TextBox> m_textboxes;
		Color m_backgroundColor;
	
	public:
		void addButton(ButtonShape shape, Color color, int x, int y, int high, int width);
		void addTextBox(std::string text, Color color, int x, int y, int size);
		void render();
		void processInput();
};
	
#endif

