
#include "GUI.h"
#include "Utils.h"

class GUIBuilder
{
	protected:
		GUI *m_gui;
	public:
		GUIBuilder();
		~GUIBuilder();
		void addButton(ButtonShape shape, Color color, int x, int y, int high, int width);
		void addTextBox(std::string text, Color color, int x, int y, int size);
		void addKeyboard(void);
		void reset();
		GUI* getResult();
};

