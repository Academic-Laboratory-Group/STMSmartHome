#ifndef _MAIN_MENU_STATE_H_
#define _MAIN_MENU_STATE_H_

#include "State.h"

class MainMenuState: public State
{
	public:
		MainMenuState();
		virtual ~MainMenuState();
		virtual void update(float deltaTime);
		virtual void render();
		virtual void processInput();
};
	
#endif
