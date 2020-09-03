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

int main(int argc, char **argv)
{

	A *ptr = new A;
	A *ptr1 = new A;
	delete ptr;
	delete ptr1;
	return 0;
}
