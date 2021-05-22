#ifndef INC_ROOMCHOOSEMENUSTATE_H_
#define INC_ROOMCHOOSEMENUSTATE_H_

#include "State.h"

class RoomChooseMenuState: public State
{
	public:
		RoomChooseMenuState(std::shared_ptr<StateManager> stateManager);
		~RoomChooseMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress) override;
};

#endif /* INC_ROOMCHOOSEMENUSTATE_H_ */
