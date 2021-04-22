#ifndef _PROG_H_
#define _PROG_H_

#define NULL ((void *)0)
	
#include "StateManager.h"
#include "Updatable.h"
#include "Renderable.h"

class Prog : public Updatable, public Renderable
{
	private:
		StateManager m_stateManager;
	
	public:    
		Prog();
		~Prog(){};
		virtual void update(float deltaTime);
		virtual void render();
		void processInput();
};

#endif
