#include <iostream>
#include <string>
using namespace std;

class A 
{
	public:
		string name = "stuart";

};

class B : public virtual A
{

};

class C : public virtual A
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
	// demonstrates that A is shared (its a pointer to a common A) in both B and C 
	d.doIt();
	return 0;
}
