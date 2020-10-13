#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>

class person
{
	std::string name;
	int age;
	std::string occupation;
	public:
	person(std::string name, int age, std::string occupation);
	std::string get_name() const {return name;}
	std::string& get_mutable_name() {return name;}

	// this << p ... this can be called as person.operator<<(p) also
	int operator<<(person &p);
	// this == other
	bool operator==(const person &other);
	
	// person >> person
	person& operator>>(person &other);
	// person >> s
	void operator>>(std::string& str);



};

#endif
