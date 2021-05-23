#ifndef _STATE_H_
#define _STATE_H_

#include "GUIBuilder.h"
#include "GUI.h"
#include "Updatable.h"
#include "Renderable.h"

#include <memory>

class StateManager;
class State : public Updatable, public Renderable
{	
	public:
		State(std::shared_ptr<StateManager> stateManager) :
			m_stateManager(stateManager), m_guiBuilder(){}
		virtual ~State() = default;

		virtual void processInput(std::pair<unsigned, unsigned> touchAddress) = 0;

	protected:
		std::shared_ptr<StateManager> m_stateManager;
		GUI m_gui;
		GUIBuilder m_guiBuilder;
};

#endif
