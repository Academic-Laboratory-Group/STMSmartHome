/*
 * NewDeviceControllingSignalMenuState.h
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#ifndef INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_
#define INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_

#include "State.h"

class NewDeviceControllingSignalMenuState: public State
{
	public:
		NewDeviceControllingSignalMenuState(StateManager* stateManager);
		virtual ~NewDeviceControllingSignalMenuState();
		virtual void update(float deltaTime);
		virtual void render();
		virtual void processInput();
};

#endif /* INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_ */
