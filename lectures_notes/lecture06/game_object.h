#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include <string>
using namespace std;

class game_object
{
	string name;
	int id;
	public:
	game_object(string name, int id);

	void print_name();
	
	// pure virtual method. virtual declares that derived classes may override it in the derived class
	// Now wont be able to instantiate a game_object. This is now an abstract class
	// Interesting note: You can have pointers to abstract class
	// in much the same way as you can use a interface in c#
	// c++ abstract class = c# interface
	virtual string get_log_prefix() = 0;
	virtual string log();
};

#endif
