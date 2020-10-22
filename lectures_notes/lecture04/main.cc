#include "bag.h"
#include <string>


int main(int argc, char** argv)
{
	// bag of integers
	bag<int> my_bag;
	my_bag.add_item(26);
	my_bag.add_item(1);
	my_bag.add_item(1987);
	my_bag.print_contents();

	std::cout << "operator[]->" << my_bag[2] << endl;
	

	// bag of strings	
	bag<std::string> your_bag;
	your_bag.add_item(string("hello, world!"));
	your_bag.print_contents();
	
	return 0;
}
