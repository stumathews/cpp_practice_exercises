#include <iostream>
using namespace std;

class A
{
	public:
		A(){
			cout << "A: default ctor called" << endl;
		}
		~A(){
			static int dtor_runs;
			cout << "A: destructor called" << endl;
			cout << "Have run " << ++dtor_runs << " times" << endl; 
		}
};

class B
{
	A a;
	public:
	B(){
		cout << "B: default ctor called" << endl;
	}

	~B(){
		cout << "B: dtor called." << endl;
	}
};

int main(int argc, char **argv)
{

	// This shows that members are initialized before the class constructor.
	// but when the class is destroyed, then only the member destructor is called.
	// its like the members are handing off the class and once the class is destroyed, they get snipped off and thus destroyed
	B *ptr = new B;
	delete ptr;
	return 0;
}
