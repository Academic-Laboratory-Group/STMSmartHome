#ifndef INC_ROOMSETTINGSMENUSTATE_H_
#define INC_ROOMSETTINGSMENUSTATE_H_

#include "State.h"
#include <iostream>
#include <string>
#include <sstream>

template < typename Type > std::string to_str (const Type & t)
{
  std::ostringstream os;
  os << t;
  return os.str ();
}

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
		float m_temperature = 29.0;
};


#endif /* INC_ROOMSETTINGSMENUSTATE_H_ */
