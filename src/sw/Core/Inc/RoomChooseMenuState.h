/*
 * RoomChooseMenuState.h
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#ifndef INC_ROOMCHOOSEMENUSTATE_H_
#define INC_ROOMCHOOSEMENUSTATE_H_

#include "State.h"

class RoomChooseMenuState: public State
{
	public:
		RoomChooseMenuState(StateManager* stateManager);
		virtual ~RoomChooseMenuState();
		virtual void update(float deltaTime);
		virtual void render();
		virtual void processInput();
};

#endif /* INC_ROOMCHOOSEMENUSTATE_H_ */
