/*
 * RoomSettingsMenuState.h
 *
 *  Created on: Apr 29, 2021
 *      Author: Krzysiek
 */

#ifndef INC_ROOMSETTINGSMENUSTATE_H_
#define INC_ROOMSETTINGSMENUSTATE_H_

#include "State.h"

class RoomSettingsMenuState: public State
{
	private:
		std::string m_name;
		std::string m_temperature;
	public:
	RoomSettingsMenuState(StateManager* stateManager);
		virtual ~RoomSettingsMenuState();
		virtual void update(float deltaTime);
		virtual void render();
		virtual void processInput();
};

#endif /* INC_ROOMSETTINGSMENUSTATE_H_ */
