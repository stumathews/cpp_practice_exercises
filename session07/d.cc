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
		virtual void action() const {
			cout << "A Action!" << endl;
		}

};

class B : public A
{
	public:
		B(){
			cout << "B default ctor" << endl;
		}
		virtual void action() const override {
			cout << "B Action!" << endl;
		}
};

class C : public A
{
	public:
		C(){
			cout << "C default ctor" << endl;
		}
		virtual void action() const override {
			cout << "C Action!" << endl;
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
		virtual void action() const override {
			cout << "D Action!" << endl;
		}
};


int main(int argc, char **argv)
{

	A a;
	B b;
	C c;
	D d;
	a.action();
	b.action();
	c.action();
	d.action();
	return 0;
}
