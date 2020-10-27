#include <iostream>
#include <list>
#include <vector>
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
	list<int> listOfIntegers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> myVec = {1, 10};
	
	size_t size = 5;
	box<int> arrayOfBoxes[size];

	for(size_t i = 0; i < size; i++) {
		box<int> &box = arrayOfBoxes[i];
		box.set_content(i);
		cout << "content of box is " << box.get_content() << endl;
	}

	box<int> *end = arrayOfBoxes + size;
	for(box<int> *i = arrayOfBoxes; i != end; i++) {
		i->set_content(i->get_content()+1);
		cout << "contents of box is " << i->get_content() << endl;
	}

	list<int>::iterator begin_list = listOfIntegers.begin();
	list<int>::iterator end_list = listOfIntegers.end();
	for(; begin_list != end_list; begin_list++)
	{
		cout << *begin_list << endl;
	}
	
	list<int> &l = listOfIntegers;
	for( list<int>::iterator b = begin(l); b != l.end(); b++) {
		cout << *b << endl;
	}

	/* auto e = end(myVec); */	
	auto e = myVec.end();	
	for(auto b = begin(myVec); b != e; b++) {
		cout << *b << endl;
	}


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
