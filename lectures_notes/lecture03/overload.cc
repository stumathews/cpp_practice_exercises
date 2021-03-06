#include <iostream>
#include "person.h"
#include <string>
using namespace std;

// cout << person   ... also note the first argument is the return value and next argument is the 2nd arg to operator
ostream& operator<<(ostream& o, person &p)
{
	return cout << p.get_name() << endl;
}



int main(int argc, char **argv)
{
	person stuart("Stuart", 33, "Programmer");
	person jenny("Jenny", 72, "mother");
	person bruce("bruce", 66, "father");

	cout << "is stuart == to jenny?:" << (stuart == jenny) << endl;
	cout << "is jenny == bruce?:" << (jenny == bruce) << endl;
	cout << "Hello World" << endl;
	cout << (stuart << jenny);
	cout << (stuart.operator<<(jenny)) << endl;

	string s;
	string &ref = s;

	// modify shift right
	stuart >> jenny;
	cout << jenny.get_name() << endl;

	cout << "reading jenny input and putting it into variable s..." << endl;
	jenny >> ref;
	cout << "s=" << s << endl;

	// overload += for person
	int age1 = stuart.get_age();
	stuart += 4;
	cout << "before stuart+=4 age is " << age1 << " and after it is " << stuart.get_age() << endl;
	

	return 0;
}
