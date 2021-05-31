#ifndef SRC_FLAT_H_
#define SRC_FLAT_H_

#include "Room.h"
#include "RoomBuilder.h"
#include "Sensor.h"
#include "Updatable.h"

#include <memory>
#include <vector>


class Flat : public Updatable
{
	public:
		Flat();
		~Flat() = default;

		using Rooms = std::shared_ptr<std::vector<std::shared_ptr<Room>>>;

		void update(float deltaTime = 0.f) override;

		void addRoom(std::shared_ptr<Room> room);
		const Rooms getRooms() const;
		const std::shared_ptr<RoomBuilder> getBuilder() const;

	private:
		std::shared_ptr<RoomBuilder> m_roomBuilder;
		std::vector<std::unique_ptr<Sensor>> m_sensors;
		Rooms m_rooms;
};


#endif /* SRC_FLAT_H_ */
