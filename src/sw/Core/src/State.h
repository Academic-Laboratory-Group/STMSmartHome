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
			m_stateManager(stateManager), m_gui(std::make_unique<GUI>()), m_guiBuilder(){}
		virtual ~State() = default;

		virtual void processInput() = 0;

	protected:
		std::weak_ptr<StateManager> m_stateManager;
		std::unique_ptr<GUI> m_gui;
		GUIBuilder m_guiBuilder;
};

#endif
