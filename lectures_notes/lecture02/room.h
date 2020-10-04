#ifndef ROOM_H
#define ROOM_H
#include "game_object.h"

class room : public game_object
{
	public:
		room();
		std::string get_position_string() const override;
		room(const game_object &other);
};

#endif
