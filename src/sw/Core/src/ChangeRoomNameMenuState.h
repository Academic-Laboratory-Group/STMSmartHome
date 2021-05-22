#ifndef INC_CHANGEROOMNAMEMENUSTATE_H_
#define INC_CHANGEROOMNAMEMENUSTATE_H_

#include "State.h"

class ChangeRoomNameMenuState: public State
{
	public:
		ChangeRoomNameMenuState(std::shared_ptr<StateManager> stateManager);
		~ChangeRoomNameMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput() override;

	private:
		std::string m_name;
};

#endif /* INC_CHANGEROOMNAMEMENUSTATE_H_ */
