
#include "GUI.h"
#include "Utils.h"

class GUIBuilder
{
	protected:
		GUI *m_gui;
	public:
		GUIBuilder();
		void addButton(ButtonShape shape, Color color, int x, int y);
		void addTextBox(char *text, Color color, int x, int y);
		void addKeyboard(void);
};

