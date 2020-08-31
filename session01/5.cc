#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	auto count = 0;
	while(getline(cin, s))
		count++;

	cout << count << endl;
}
