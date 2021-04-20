#ifndef _PROG_H_
#define _PROG_H_

#define NULL ((void *)0)
	
#include "StateManager.h"
#include "Updatable.h"
#include "Renderable.h"

class Prog : public Updatable
{
	private:
		Prog();
		~Prog();
    Prog(Prog &other){};
    void operator=(const Prog &){};
	
	
		// Singleton instance
		static Prog* m_instance;
		StateManager m_stateManager;
	
	public:    
		static Prog* getInstance();
		virtual void update(float deltaTime);
		virtual void render();
		void processInput();
};

#endif
