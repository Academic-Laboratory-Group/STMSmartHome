#ifndef _GUI_H_
#define _GUI_H_

#include "Button.h"
#include "TextBox.h"
#include "Utils.h"
#include "Renderable.h"

#include <vector>
#include <memory>
#include <string>


class GUI : public Renderable
{
	public:
		GUI() : m_backgroundColor(WHITE) {};
		~GUI() = default;

		void render() override;
		int processInput(std::pair<unsigned, unsigned> touchAddress);

		void addButton( std::shared_ptr<Button> button );
		void addTextBox( std::shared_ptr<TextBox> textBox );

		void setBackgroundColor(Color color);

		std::string getButtonText(int idx);
		void setTextBoxText(int idx, std::string name);

	private:
		std::vector<std::shared_ptr<Button>> m_buttons;
		std::vector<std::shared_ptr<TextBox>> m_textBoxes;
		Color m_backgroundColor;
};

	
#endif
