#ifndef SPECIAL_BAG
#define SPECIAL_BAG
#include "bag.h"
#include <vector>

template <typename T>
class special_bag : public bag<T>
{
	public:
	special_bag(vector<T> things) : bag<T>(things){}
	void printThings() override;
};

template <typename T>
void special_bag<T>::printThings()
{
	cout << "Specialized overridedn print" << endl;
	int counter = 0;
	for(auto b = begin(bag<T>::contents); b != end(bag<T>::contents);b++ ) 
	{
		cout << ++counter << ". " << *b << " (special)" << endl;
	}
}

#endif

