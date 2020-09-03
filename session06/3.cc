#include <iostream>
#include <string>

using namespace std;

class Pet {
protected:
	string _name;
public:
	Pet(string name) : _name(name) {}
	virtual string sound() const = 0;
	virtual void speak() const {
		cout << _name << ": " << sound() << "!\n";
	}
};

class Dog : public Pet {
public:
	Dog(string name) : Pet(name) {}
	virtual string sound() const { return "woof"; }
	virtual void speak() const;
};

void Dog::speak() const {
	Pet::speak();
	cout << '(' << _name << " wags tail)\n";
}

class Dalmatian : public Dog {
	int _spots;
public:
	Dalmatian(string name, int spots) :
		Dog(name), _spots(spots) {}
};

class Cat : public Pet {
public:
	Cat(string name) : Pet(name) {}
	virtual string sound() const { return "miao"; }
};

void speakTwice(const Pet &pet) {
	pet.speak();
	pet.speak();
}

int main(int argc, char** argv)
{
	Dog lassie("lassie");
	Dalmatian spotty("spotty", 12);
	Cat garfield("garfield");
	Pet rodent("rodent");
	return 0;
}
