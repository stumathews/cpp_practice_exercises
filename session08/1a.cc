#include <iostream>
using namespace std;

class MyClass
{
	public:
		MyClass(){
			cout << "MyClass: default ctor called" << endl;
		}
		~MyClass(){
			cout << "MyClass: destructor called" << endl;
		}
};

int main(int argc, char **argv)
{

	MyClass mc;
	return 0;
}
