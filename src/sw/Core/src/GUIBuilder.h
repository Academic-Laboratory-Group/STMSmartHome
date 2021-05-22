
#include "GUI.h"
#include "Utils.h"

#include <memory>

class GUIBuilder
{
	protected:
		std::unique_ptr<GUI> m_gui;
	public:
		GUIBuilder();
		~GUIBuilder() = default;

		void addButton(ButtonShape shape, Color color, int x, int y, int high, int width);
		void addTextBox(std::string text, Color color, int x, int y, int size);
		void addKeyboard(void);
		void setBackgroundColor(Color color);
		void reset();
		std::unique_ptr<GUI> getResult();
};

