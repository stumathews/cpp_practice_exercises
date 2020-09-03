#include <iostream>
#include <string>
using namespace std;

class A 
{
	public:
		string name = "stuart";
		A() { cout << "A" << endl; }

};

class B : public virtual A
{
	public:
		B() { cout << "B" << endl;}
};

class C : public virtual A
{
	public:
		C() { cout << "C" << endl;}
};

class D : public B, public C
{
	public:
		void doIt(){
			B::name = "Bertrude";
			cout << "B:" << B::name << " C:" << C::name << endl;
		}
		D() { cout << "D" << endl;}
};


int main(int argc, char **argv)
{

	D d;
	// demonstrates that A is shared (its a pointer to a common A) in both B and C 
	// Also shows that once a virtual base class is created, it is not created again by subsequent desrived classes of that virtual base class
	d.doIt();
	return 0;
}
