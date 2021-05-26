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
		enum class Buttons
		{
			Back,
			LightUp,
			LightDown,
			HeaterUp,
			HeaterDown,
		};
		std::string m_name;
		float m_temperature = 29.0f;
};


#endif /* INC_ROOMSETTINGSMENUSTATE_H_ */
