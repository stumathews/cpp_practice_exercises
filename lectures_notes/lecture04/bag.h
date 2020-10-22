#ifndef BAG_H
#define BAG_H
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class bag
{
	std::vector<T> contents;
	public:
	void add_item(T item);
	void print_contents(); 
	T operator[](size_t index);
};


// Note that the function definitions for template function from templated classed must exist in the same file as the class declaration!!


template <typename T>
void bag<T>::add_item(T item)
{
	contents.push_back(item);
}

template <typename T>
void bag<T>::print_contents() 
{
	cout << "Printing contents of bag:" << endl;
	if(contents.size() == 0)
		cout << "bag is empty." << endl;

	for(auto b = begin(contents); b != end(contents);b++)
	  cout << *b << endl;	
}

// OR included for the implementation file:

#include "bag.cc"

// but cannot be split into an implementation file (.cc) file alone
// as both the declaration and definition file needs to be available
// when the compiler comes across a usage of bag<int,char*, etc> 
#endif
