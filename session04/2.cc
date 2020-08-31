#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	string s;
	map<string, int> occur;
	vector<string> words;
	while((cin >> s)) {
		if(occur.count(s)){
			occur[s]++;
		} else {
			occur[s] = 1;
			words.push_back(s);
		}
	}
	for(int i = 0; i < words.size();i++)
		cout << words[i] << " count:" << occur[words[i]] << endl;
	return 0;
}
