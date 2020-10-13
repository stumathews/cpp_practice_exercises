#include "person.h"

person::person(std::string name, int age, std::string occupation): name(name), age(age), occupation(occupation)
{

}
bool person::operator==(const person &p)
{
	return this->get_name().size() == p.get_name().size();
}
person& person::operator>>(person &other)
{
	other.get_mutable_name().append(other.get_name());
	return other;
}

int person::operator<<(person &p)
{
	return p.get_name().size();
}

void person::operator>>(std::string& str)
{
	str = this->get_mutable_name();
}
