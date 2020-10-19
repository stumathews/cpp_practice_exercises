#include "bag.h"
#include <string>

int main(int argc, char** argv)
{
	bag<int> my_bag;
	bag<std::string> your_bag;
	my_bag.add_item(26);
	your_bag.add_item(string("hello, world!"));

	my_bag.print_contents();
	your_bag.print_contents();




	
	return 0;
}
