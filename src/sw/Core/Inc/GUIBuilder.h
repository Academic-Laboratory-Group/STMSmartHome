
#include "GUI.h"
#include "Utils.h"

class GUIBuilder
{
	protected:
		GUI *m_gui;
	public:
		GUIBuilder();
		~GUIBuilder();
		void addButton(ButtonShape shape, Color color, int x, int y);
		void addTextBox(std::string text, Color color, int x, int y);
		void addKeyboard(void);
		void reset();
		GUI* getResult();
};

