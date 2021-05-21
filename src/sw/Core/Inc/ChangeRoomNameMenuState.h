/*
 * ChangeRoomNameMenuState.h
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#ifndef INC_CHANGEROOMNAMEMENUSTATE_H_
#define INC_CHANGEROOMNAMEMENUSTATE_H_

#include "State.h"

class ChangeRoomNameMenuState: public State
{
	private:
		std::string m_name;
	public:
		ChangeRoomNameMenuState(StateManager* stateManager);
		virtual ~ChangeRoomNameMenuState();
		virtual void update(float deltaTime);
		virtual void render();
		virtual void processInput();

};

#endif /* INC_CHANGEROOMNAMEMENUSTATE_H_ */
