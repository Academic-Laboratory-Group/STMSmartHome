#ifndef _GUI_H_
#define _GUI_H_

#include <iostream>
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
		void addButton();
		void addTextBox();
		void render();
		void processInput();
};
	
#endif