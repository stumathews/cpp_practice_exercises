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
};

int main(int argc, char **argv)
{
	B b1;
	B b2;
	B b3;

	// double free: b3 contains the same address of a as b2 as it was a memberwise copy performed by the generated assignment operator
	b3 = b2;
	// double free: b4 contains the same address of a as b3 as it was a memberwise copy performed by the generated copy ctor
	B b4 = b3;

	return 0;
}
