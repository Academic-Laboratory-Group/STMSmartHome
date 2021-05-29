#ifndef INC_CHANGEROOMNAMEMENUSTATE_H_
#define INC_CHANGEROOMNAMEMENUSTATE_H_

#include "State.h"
#include "Room.h"

#include <string>


class ChangeRoomNameMenuState: public State
{
	public:
		ChangeRoomNameMenuState(std::shared_ptr<StateManager> stateManager,
				std::shared_ptr<Room> room);
		~ChangeRoomNameMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress) override;

	private:
		std::shared_ptr<Room> m_room;
		std::string m_newName;
};

#endif /* INC_CHANGEROOMNAMEMENUSTATE_H_ */
