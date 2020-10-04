#include "game_object.h"
#include <iostream>
using namespace std;

void game_object::print_position() const
{
	cout << "(" << _x << "," << _y << ")" << endl;
	if(_pchild)
		cout << "child: " <<"(" << _pchild->_x << "," << _pchild->_y << ")" << endl;

}

game_object::game_object() : _x(0),_y(0) /* This is an initialization list, before the body of the constructor */
{

}

game_object::game_object(int x, int y)
{
	_x = x;
	_y = y;
}

game_object::~game_object()
{
	cout << "Game object destroyed" << endl;
}

void game_object::add_child(const game_object* p_child)
{
	_pchild = p_child;
}

game_object::game_object(const game_object &other)
{
	_x = other.get_x(); // these functions need to be const, as the object is const
	_y = other.get_y();
}

const game_object& game_object::operator=(const game_object &other)
{
	_x = other.get_x(); //note that get_x() must be const as other is const to ensure that no changes are occuring to other
	_y = other.get_y();
	return *this;
}

string game_object::get_position_string() const
{
	// creates a series of tempory string objeects
	return string("(") 
		+ string(std::to_string(_x)) 
		+ string(",") + string(std::to_string(_y)) 
		+ string(")"); 
}
