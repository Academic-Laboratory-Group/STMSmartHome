#ifndef _MAIN_MENU_STATE_H_
#define _MAIN_MENU_STATE_H_

#include "State.h"

class MainMenuState: public State
{
	public:
		MainMenuState(std::shared_ptr<StateManager> stateManager);
		~MainMenuState() = default;
		void update(float deltaTime) override;
		void render() override;
		void processInput() override;
};
	
#endif
