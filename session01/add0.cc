// To run this:
// Type two integers separated by a space and press return.
// To stop the program type two zeros: 0 0
//
#include <iostream>
#include <climits>
using namespace std;

auto add_by_1 = []( int a, int b ) {
	while(b-- > 0)
		a += 1;
	return a;
};

auto mult = []( int a, int b ) {
	int z = 0;
	auto end = a - 1;
	while(a >= end)
		z = add_by_1(a-- * z,b);
	return z;
};

int main() {
	int i, j;

	while (cin >> i >> j && (i != 0 || j != 0)){
		cout << i << " + " << j << " = " << add_by_1(i, j) << endl;
		cout << i << " * " << j << " = " << mult(i, j) << endl;
	}

	i = 0; j = 0;
	cout << i << " + " << j << " = " << add_by_1(i, j) << endl;
	cout << i << " * " << j << " = " << mult(i, j) << endl;

	return 0;
}
