#ifndef INC_ROOMSETTINGSMENUSTATE_H_
#define INC_ROOMSETTINGSMENUSTATE_H_

#include "State.h"
#include "Room.h"

#include <string>

class RoomSettingsMenuState: public State
{
	public:
		RoomSettingsMenuState(std::shared_ptr<StateManager> stateManager,
				std::shared_ptr<Room> room);
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
		enum class TextBoxes
		{
			Name,
			Light,
			Heater,
			Intensity,
			Temperature,
			RoomTemperature,
			RoomTemperatureValue,
			RoomTemperatureDegrees,
		};
		std::shared_ptr<Room> m_room;
		float m_temperatureToSet = 22.65f;
		int m_intensityToSet = 0;
};


#endif /* INC_ROOMSETTINGSMENUSTATE_H_ */
