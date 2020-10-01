#include <iostream>
#include <vector>
using namespace std;

using namespace std;

class Person
{
	string _name;
	public:
		Person(string &name) : _name(name){};
		Person(): _name("NoName") {}
		Person(const Person& other);  // Copy constructor does not return a type as you are setting yourself

		const Person& operator=(const Person &other); // Assignment operator

		string get_name() const { return _name; };
		void set_name(string name) { _name = name;}
		void print();

};

const Person& Person::operator=(const Person &other)
{
	cout << "Assignment operator is called and it is not a constructor" << endl;
	return *this;
}

Person::Person(const Person &copy)
{
	cout << "Copy constructor called!" << endl;
	set_name(copy.get_name());
}

void Person::print()
{
	cout << "Person name is " << _name << endl;
}

int main(int argc, char** argv)
{
	vector<Person> persons;

	string name = "Person2";
	cout << "Hello World" << endl;
	Person p1;
	Person p2(name);
	Person p3(p2);
	p1 = p3;
	p1.print();
	p2.print();
	p3.print();

	persons.push_back(p1);
	persons.push_back(p2);
	persons.push_back(p3);

	for(auto b = begin(persons); b != end(persons);b++) {
		b->print();
	}
}
