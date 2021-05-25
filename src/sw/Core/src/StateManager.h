#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "State.h"
#include "Updatable.h"
#include "Renderable.h"

#include <memory>

class StateManager : public Updatable, Renderable
{
	public:
		StateManager();
		~StateManager() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress);

		void changeState(std::unique_ptr<State> state);

	private:
		std::unique_ptr<State> m_currentState;
};

#endif
