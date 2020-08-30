#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
	// standard out
	cout << "Hello World! What is your name? Type it in:" << endl;
	string name;
	
	// standard input
	cin >> name;
	cout << "Hello, " << name << ", nice to have you with us!" << endl;

	// error
	cerr << "This is a error notice";

}
