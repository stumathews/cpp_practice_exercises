#include <list>
#include <iostream>
using namespace std;

void print_doubles(list<int> &l)
{
	for(auto b = begin(l); b != end(l);b++) {
		*b *=2;
		cout << *b << endl;
	}
}

int main(int argc, char**argv)
{
	list<int> numbers = {1,2,3,4,5,6,7,8,9,10};
	print_doubles(numbers);

	return 0;
}
