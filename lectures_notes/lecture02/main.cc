#include "game_object.h"
#include "room.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	game_object o1; // constructor initialization - see type is specified
	game_object o2(12,500); // constructor initialization
	game_object o3(o2); // constructor - copy (form1)
	game_object o4, o5;
	game_object o6 = o2; // constructor - copy (form2)

	// Invoke game_object's assignment operator
	o4 = o1;
	o5 = o2;

	// Make aliases for object i.e references
	game_object &a1 = o1;
	const game_object &a2 = o2;

	// Make pointers of game_object
	game_object *p1 = &o1;
	game_object const *p2 = &o2;

	// pass a pointer to a game_object
	p1->add_child(&o1);
	
	// access game_object member function
	o1.print_position();
	a1.print_position();
	p1->print_position();
	o2.print_position();
	a2.print_position();
	p2->print_position();
	o3.print_position();
	o4.print_position();
	o5.print_position();
	o6.print_position();

	// temporary objects
	cout << "temp object position: " << game_object().get_position_string() << endl;

	// Rooms:
	room r1(o2);
	cout << r1.get_position_string() << endl;

	return 0;
}
