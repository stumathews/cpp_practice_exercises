#include <cassert>
#include <string>
#include <iostream>
using namespace std;
class bank
{
	string _name;
	int _balance;
public:
	bank(string name, int balance) : _name(name), _balance(balance){} 

	string get_name() { return _name; }
	int get_balance() { return _balance; }

	void deposit_money(int money) { _balance += money; }
	void withdraw_money(int amount) { _balance -= amount; }
};

int main(int argc, char** argv)
{
	bank bank1("fnb", 1000);
	bank bank2("standard", 2000);

	assert(bank1.get_name() == "fnb");
	assert(bank2.get_name() == "standard");
	assert(bank1.get_balance() == 1000);
	assert(bank2.get_balance() == 2000);

	bank1.deposit_money(1);
	assert(bank1.get_balance() == 1001);
	bank1.withdraw_money(1000);
	assert(bank1.get_balance() == 1);
	
	cout << bank1.get_name() <<" has " << bank1.get_balance() << " in cash." << endl; 
	cout << bank2.get_name() <<" has " << bank2.get_balance() << " in cash." << endl; 

}
