#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
	string s;
	map<string, int> occur;
	map<string, int> sum;
	vector<string> words;

	auto count = 1;
	string prvWord;
	while((cin >> s)) {
		auto isWord = count++ % 2 != 0;
		if(isWord) {
			prvWord = s;
			if(occur.count(s)){
				occur[s]++;

			} else {
				occur[s] = 1;
				sum[s] = 0;
				words.push_back(s);
			}
		} else {
			sum[prvWord] += std::atoi(s.c_str());
		}
	}

	for(int i = 0; i < words.size();i++){
		auto &word = words[i]; 
		cout << word << " count:" << occur[word] << " sum:" << sum[word] << " ave: " << sum[word] / occur[word]   << endl;
	}
	return 0;
}
