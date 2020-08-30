#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{

	// When the type is specified, its a constructor, when its not, and there is an assignment, its likely to be 
	// a assignment operator being invoked

	// call default constructor to initialize the vector
	vector<string> names;

	names.push_back("Stuart");
	names.push_back("Bruce");
	names.push_back("Jenny");

	// call constructor with 1 arg
	string s("stuart");

	cout << "s: he string was initialized with the value: " << s << endl;

	// This is a copy constructor - type 'string' is specified. 
	// A copy constructor has the same type as the only argument, ie string(const string &other)
	// It is left associated, so t = s, = is associated with t such that the copy constuctor is defined in t
	string t = s;

	cout << "a copy of s is t:" << t << endl;

	string u("hello");

	// Copy via assignment operator. Remember an assignment replaces an existing value
	s = u; // no type specified but is an assignment, so assignment operator is used
	cout << "s is now " << s << endl;
	
	// Important to note that these are all copy operations ie copying the object that the variables are all referring to

}
