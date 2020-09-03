#include <iostream>
#include <string>
using namespace std;

class A 
{
	public:
		string name = "stuart";

};

class B : public A
{

};

class C : public A
{
};

class D : public B, public C
{
	public:
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
