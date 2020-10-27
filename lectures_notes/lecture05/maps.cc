#include <iostream>
#include <list>
#include <vector>
#include <map>
using namespace std;

template <typename T>
class box
{
	T content;
	public:
	box(T the_content): content(the_content){}
	box() {content = 0;}
	void set_content(T content) { this->content = content; }
	T get_content() const;
};

template<typename T>
T box<T>::get_content() const 
{
	return content;
}

int main(int argc, char **argv)
{
	box<int> boxOfIntegers(12);
	box<int> boxOfIntegers2(13);
	list<int> listOfIntegers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> myVec = {1, 10};
	map<string, box<int>> cubbyHoles;

	cubbyHoles["stuart"] = boxOfIntegers;
	cubbyHoles["jenny"] = boxOfIntegers2;

	cout << "Jennys cubby hole contains " << cubbyHoles["jenny"].get_content() << endl;
	cout << "Stuarts cubby hole contains " << cubbyHoles["stuart"].get_content() << endl;

	for(auto b = begin(cubbyHoles); b != end(cubbyHoles);b++)
	{
		pair<const string, box<int>> it = *b;
		auto name = b->first;
		auto box = b->second;
		cout << name << " -> " << box.get_content() << endl;
		cout << it.first << " -> " << it.second.get_content() << endl;
	}
	
	size_t size = 5;
	box<int> arrayOfBoxes[size];

	cout << "The contents of the box is " << boxOfIntegers.get_content() << endl;

	box<int> *pointerToBox = &boxOfIntegers;
	pointerToBox->set_content(24);
	cout << "The contents of the box is " << pointerToBox->get_content() << endl;

	box<int> * const cPointer = &boxOfIntegers;
	cPointer->set_content(48);
	cout << "The contents of the box is " << cPointer->get_content() << endl;
	
	box<int> &alias = boxOfIntegers;
	alias.set_content(96);
	cout << "The contents of the box is " << alias.get_content() << endl;
	
	box<int> * const *ppi = &cPointer;
	(**ppi).set_content(192);
	cout << "The contents of the box is " << (**ppi).get_content() << endl;
	cout << "pointers!" << endl;
	return 0;
}
