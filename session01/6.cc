#include <string>
#include <iostream>
using namespace std;

int main() {
	string s;
	auto longest_length = 0;
	string longest_line;
	
	while(getline(cin, s))
	{
		auto slen = s.length();
		if( slen > longest_length){
			longest_line = s;
			longest_length = slen;
		}	
	}

	cout << "Longest line has " << longest_length << " characters and is '"<< longest_line << "'"  << endl;
}
