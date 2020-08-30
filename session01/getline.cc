#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string name("Stuart"); // initialized         
	cout << "Whats your name?" << endl;

	// getline takes a reference to an iostream and a string and modifies the string in place
	// the result of getline is >0 is OK else problem occurred
	while(getline(cin, name) && name != "q")
	{
		cout << name << endl;
		cout << "Whats your name?" << endl;
	}
	return 0;

	// Its important to remember that on calling a function, the actual arguments are copied into the formal parameters
	// when returning the returned result is copied to the caller ... unless passing in or returning references
}
