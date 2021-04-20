#ifndef _STATE_H_
#define _STATE_H_

#include "StateManager.h"
#include "GUIBuilder.h"
#include "GUI.h"
#include "Updatable.h"
#include "Renderable.h"

class State : public Updatable, public Renderable
{	
	protected:
		StateManager m_stateManager;
		GUI* m_gui;
		GUIBuilder m_guiBuilder;
	public:
		virtual ~State(){};
		virtual void processInput() = 0;
};

#endif
