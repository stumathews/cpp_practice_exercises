#include "room.h"

room::room() : game_object()
{
}

std::string room::get_position_string() const 
{
	auto s = game_object::get_position_string();
	return std::string("Room:") + s;
}

room::room(const game_object &other)
{
	_x = other.get_x();
	_y = other.get_y();
}
