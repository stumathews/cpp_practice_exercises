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
};

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
#endif
