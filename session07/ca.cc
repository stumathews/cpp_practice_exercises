#include <iostream>
#include <string>
using namespace std;

class A 
{
	public:
		A(){
			cout << "A default ctor" << endl;
		}
		string name = "stuart";

};

class B : public A
{
	public:
		B(){
			cout << "B default ctor" << endl;
		}
};

class C : public A
{
	public:
		C(){
			cout << "C default ctor" << endl;
		}
};

class D : public B, public C
{
	public:
		// see output but it executes the base class constructors first before call itself
		// We know this from the order or initialization ie base constructors first, then members, then our constructor
		D(){
			
			cout << "D default ctor" << endl;
		}
		void doIt(){
			B::name = "Bertrude";
			cout << "B:" << B::name << " C:" << C::name << endl;
		}
};


int main(int argc, char **argv)
{

	D d;
	// Demonstrates that two copies of A are replicated when inheriting B and C (as thee both inherit from A)
	d.doIt();
	return 0;
}
