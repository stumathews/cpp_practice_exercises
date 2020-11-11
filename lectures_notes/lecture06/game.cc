#include <iostream>
#include "ball.h"
/* #include "game_object.h" */
using namespace std;


void log_game_object(game_object& go)
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
	return 0;
}
