#ifndef BAG_H
#define BAG_H

#include <vector>

template <typename T>
class bag
{
	protected:
	vector<T> contents;
	public:
	bag(vector<T> things);
	void addThing(T thing);
	virtual void printThings();
};

template <typename T>
bag<T>::bag(vector<T> things) : contents(things)
{
	cout << "Bag initialized" << endl;
	printThings();
}
template <typename T>
void bag<T>::addThing(T thing)
{
	contents.push_back(thing);
}

template <typename T>
void bag<T>::printThings()
{
	cout << "Printing contents: " << endl;
	int counter = 0;
	for(auto b = begin(contents); b != end(contents);b++ ) 
	{
		cout << ++counter << ". " << *b << endl;
	}

}
#endif
