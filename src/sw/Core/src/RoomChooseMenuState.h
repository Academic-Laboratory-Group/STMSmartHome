#ifndef INC_ROOMCHOOSEMENUSTATE_H_
#define INC_ROOMCHOOSEMENUSTATE_H_

#include "Room.h"
#include "State.h"

class RoomChooseMenuState : public State
{
	public:
		RoomChooseMenuState(std::shared_ptr<StateManager> stateManager);
		~RoomChooseMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress) override;

	private:
		enum class Buttons
		{
			Back,
			Room,
			NewRoom
		};
};

#endif /* INC_ROOMCHOOSEMENUSTATE_H_ */
