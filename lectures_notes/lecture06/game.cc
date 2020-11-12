#include <iostream>
#include "ball.h"
#include "bag.h"
#include "special_bag.h"
#include <memory>
using namespace std;

// Dynamic binding used here because we used a reference to a base class
void log_game_object(game_object& go) // see you cannot pass an abstract class by value (as we cannot constuct it to copy it!)
{
	cout << "Logging game object:" << go.log() << endl;
}

int main(int argc, char**argv)
{
	ball my_ball;
	my_ball.print_name();

	cout << "my_ball prefix: " << my_ball.get_log_prefix() << endl;
	cout << "my_ball log: " << my_ball.log() << endl;
	log_game_object(my_ball);
	my_ball.do_physics();

	vector<string> names = {"Stuart", "Jenny", "Bruce"};
	bag<string> string_bag(names);
	string_bag.printThings();

	special_bag<string> special_strings(names);
	special_strings.printThings();

	/* shared_ptr<ball*> aBall = make_shared<ball*>(new ball()); */
	ball *aBall = new ball();
	delete aBall;

	shared_ptr<string> s = make_shared<string>("foo"); // works
	shared_ptr<ball> ss = make_shared<ball>(new ball()); // doens't work!


	return 0;
}
