#include "game_object.h"
#include <iostream>
using namespace std;

game_object::game_object(string name, int id) : name(name), id(id)
{
	cout << "Game Object initialized." << endl;
}	

void game_object::print_name()
{
	cout << "Name: " << name << endl;
}

string game_object::log()
{
	return "game_object's log()";
}
void game_object::do_physics()
{
	cout << "Doing physics..." << endl;
}
