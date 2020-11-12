#ifndef BALL_H
#define BALL_H
#include "game_object.h"
#include <iostream>
using namespace std;
// This syntax says make all the public members of game_object also public in ball
// i.e it always considers the public member in the base class and how the derived class they will be represented
class ball : public game_object
{
	public:
	ball();
	string get_log_prefix() override;
	string log() override;
	void do_physics() final;
	~ball();
	ball(ball *ptr);
};

ball::ball(ball *ptr) : game_object("dude", 12)
{

}

ball::~ball()
{
	cout << "destroying ball" << endl;
}
void ball::do_physics()
{
	cout << "Ball is doing its own physics" << endl;
}

string ball::log()
{
	return "ball's Log()";
}

string ball::get_log_prefix()
{
	return "ball::";
}


ball::ball() : game_object("my ball", 1) // we have to specify a constructor as there isn't a default constructor in game_object, which would normally be called automatically
{
	cout << "Ball created." << endl;

}

#endif
