#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<string> lines;
	auto longest_length = 0;
	string longest_line;
	
	while(getline(cin, s))
		lines.push_back(s);

	auto size = lines.size()-1;
	for(int i = size;i >=0;i--)
		cout << lines[i] << endl;
}
