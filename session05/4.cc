#include <vector>
#include <list>
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	list<int> numbers = { 1, 2,3,4,5 };
	list<int>::iterator l_it = begin(numbers);
	list<int>::iterator l_it_end = end(numbers);

	l_it_end--;
	l_it_end--;

	vector<int> v(l_it, l_it_end );
	for(auto b = begin(v); b != end(v);b++)
	{
		cout << *b << endl;
	}
	return 0;
}
