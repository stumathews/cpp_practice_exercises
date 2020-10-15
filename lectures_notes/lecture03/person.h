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
	int get_age() const { return age; }

	// this << p ... this can be called as person.operator<<(p) also
	int operator<<(person &p);
	// this == other
	bool operator==(const person &other);
	
	// person >> person
	person& operator>>(person &other);
	// person >> s
	void operator>>(std::string& str);

	// int i = +5 
	// |-> this is a unary plus operator	
	
	// ++a -> a.operator++()
	int operator++()
	{
		int old_age = this->age;
		return ++this->age;
	}
	
	// a++ -> a.operator++(int)
	int operator++(int)
	{
		int old_age = this->age;
		this->age++;
		return old_age;
	}
	
	// person+= 4; will allow to modify 
	person & operator+=(int i)
	{
		this->age += 4;
		return *this;
	}
	
	



};

#endif
