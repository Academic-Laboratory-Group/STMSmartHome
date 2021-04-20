#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "Updatable.h"
#include "Renderable.h"

class State;
class StateManager
{	
	private:
		State* m_currentState;
	public:
		StateManager();
		~StateManager();
		virtual void update(float deltaTime);
		virtual void render();
		void processInput();
};

#endif
