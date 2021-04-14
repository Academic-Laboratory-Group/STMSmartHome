
#include "GUI.h"
#include "Utils.h"

class GUIBuilder
{
	protected:
		GUI *m_gui;
	public:
		GUIBuilder();
	  ~GUIBuilder();
		void addButton( ButtonShape shape, Color color);
		void addTextBox( Color color);
		void addKeyboard( Color color);
};

