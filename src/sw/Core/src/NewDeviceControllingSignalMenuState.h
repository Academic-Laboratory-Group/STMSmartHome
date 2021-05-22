#ifndef INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_
#define INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_

#include "State.h"

class NewDeviceControllingSignalMenuState: public State
{
	public:
		NewDeviceControllingSignalMenuState(std::shared_ptr<StateManager> stateManager);
		~NewDeviceControllingSignalMenuState() = default;

		void update(float deltaTime) override;
		void render() override;
		void processInput() override;
};

#endif /* INC_NEWDEVICECONTROLLINGSIGNALMENUSTATE_H_ */
