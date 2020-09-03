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
	A *a;
	public:
	B(){
		cout << "B: default ctor called" << endl;
		a = new A;
	}

	~B(){
		cout << "B: dtor called." << endl;
		delete a;
	}

	// A copy constructor just like any other constructor has no return type	
	B(const B &other) : a(new A)
	{
		*a = *other.a;
	}
};

int main(int argc, char **argv)
{
	B b1;
	B b2;
	// b1 contains a memberwise copy of the pointer to A, when both b1 and b2 are deleted when they go out of scope, 
	// the dtor of both try to delete the same block of memory, the 2nd time this occurs - it crashes or detects a double free.
	B b3 = b2;
	return 0;
}
