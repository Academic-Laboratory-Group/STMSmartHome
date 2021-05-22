#ifndef INC_ROOMSETTINGSMENUSTATE_H_
#define INC_ROOMSETTINGSMENUSTATE_H_

#include "State.h"

class RoomSettingsMenuState: public State
{
	public:
		RoomSettingsMenuState(std::shared_ptr<StateManager> stateManager);
		~RoomSettingsMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput(std::pair<unsigned, unsigned> touchAddress) override;

	private:
		std::string m_name;
		std::string m_temperature;
};

#endif /* INC_ROOMSETTINGSMENUSTATE_H_ */
