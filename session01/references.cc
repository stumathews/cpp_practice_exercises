#include <iostream>
#include <vector>

using namespace std;

void heavyProcessing(vector<int> &vec)
{
	// vec is an alias, its just another name for numbers and you can interact with it just as you could 'numbers'
	// use it as if it is the original numbers vector...because it is!
	auto last = vec[vec.size()-1];
	auto first = vec[0];
	cout << "first number is " << first << " and last is " << last << endl;
	cout << "I'm doing some heavy work on a reference to vector" << endl;
}
int main() {
	
	vector<int> numbers = {1,2,3,4,5};

	// Key aspect is that the formal argument vec is not initialized with a copy of the actual argument, numbers
	heavyProcessing(numbers);

	int twenty = 20;
	int &also_twenty = twenty;

	// References are great for renaming and adding more descriptive names to existing variables
	cout << "How much: " << also_twenty << endl;



        return 0;
}

