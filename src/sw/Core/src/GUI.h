#ifndef _GUI_H_
#define _GUI_H_

#include "Button.h"
#include "TextBox.h"
#include "Utils.h"
#include "Renderable.h"

#include <vector>
#include <memory>


class GUI : public Renderable
{
	public:
		GUI() : m_backgroundColor(WHITE) {};
		~GUI() = default;

		void render() override;
		int processInput(std::pair<unsigned, unsigned> touchAddress);

		void addButton(ButtonShape shape, Color color, unsigned xCenter, unsigned yCenter,
				unsigned width, unsigned high);
		void addTextBox(std::string text, Color color, unsigned xCenter, unsigned yCenter,
				unsigned size);
		void setBackgroundColor(Color color);

	private:
		std::vector<std::shared_ptr<Button>> m_buttons;
		std::vector<std::shared_ptr<TextBox>> m_textboxes;
		Color m_backgroundColor;
};

	
#endif
