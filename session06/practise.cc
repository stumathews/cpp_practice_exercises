#include <string>
#include <iostream>
using namespace std;

class Being
{
protected:
	string _identifier;
public:
	Being() { _identifier = "<no identity>"; }
	Being(string name) : _identifier(name){}
	string GetIdentifier() const { return _identifier; }

	virtual void wave() const = 0;
	virtual void jump() const {
		cout << "The Being lifts itself from the earth temporarily." << endl;
	}
};

class Human : public Being
{
public:
	Human(string name) : Being(name) {}
	virtual void wave() const { 
		cout << "The human by the name of " << GetIdentifier() << " waves casually." << endl; 
	}
};

class Animal : public Being
{
public:
	Animal(): Being() {}
	Animal(string name) : Being(name) {}
	virtual void wave() const override {
		cout << "The animal("<< GetIdentifier() <<") makes an apparent waving gesture..." << endl;
	}
	virtual void jump() const override {
		cout << "The animal("<< GetIdentifier() <<") lifts itself up and puts itself down again...it jumped." << endl;
	}
};

int main(int argc, char **argv)
{
	Human Stuart("Stuart");
	Animal hedgehog("mary");
	
	Animal fox; // note to self about default constructors: Animal fox() tries to declare a function called fox() that returns an Animal! and not the default constructor!

	Stuart.jump();
	Stuart.wave();
	hedgehog.jump();
	hedgehog.wave();
	fox.jump();
	fox.wave();

	// using interfaces or base class pointers/references
	
	cout << "Now using base pointers/references..." << endl;
	cout << "Stuart:" << endl;	
	Being &interface = Stuart;
	interface.jump();
	interface.wave();

	cout << "fox:" << endl;	
	Being &interface1 = fox;
	interface1.jump();
	interface1.wave();
	return 0;
}
