#include <list>
#include <iostream>
using namespace std;

template <typename T>
void print_doubles(list<T> &l)
{
	for(auto b = begin(l); b != end(l);b++) {
		*b *=2;
		cout << *b << endl;
	}
}

int main(int argc, char**argv)
{
	list<int> numbers = {1,2,3,4,5,6,7,8,9,10};
	list<float> numbers1 = {1.2,2.3,3.4,4.5,5.6,6.7,7.8,8.9,9.10,10.100};
	print_doubles(numbers);
	print_doubles(numbers1);

	return 0;
}
