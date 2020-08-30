#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
	// vector of strings. It is a generic class
	vector<string> names;
	names.push_back("Stuart");
	names.push_back("Bruce");
	names.push_back("Jenny");

	// Size of the vector via size() function
	cout << "We have " << names.size() << " elements in the vector." << endl;

	// Note: names[0] is actually the function names.operator[](0)
	cout << "The first item is " << names[0] << endl;

}
