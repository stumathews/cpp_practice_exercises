#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char **argv)
{
	string word;
	map<string,int> occurs;
	
	while(cin >> word) {
		occurs[word]++;
		cout << word << endl;
	}

	for(auto b = begin(occurs); b != end(occurs);b++){
		cout << b->first << " occurred " << b->second << " times." << endl;
	}
	return 0;
}
