#ifndef _MAIN_MENU_STATE_H_
#define _MAIN_MENU_STATE_H_

#include "State.h"
#include "Room.h"

class MainMenuState: public State
{
	public:
		MainMenuState(std::shared_ptr<StateManager> stateManager);
		~MainMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress) override;

	private:
		enum class Buttons
		{
			Adjust
		};
		int m_temp_first_room = 22.0;
		int m_temp_second_room = 23.0;
};
	
#endif
