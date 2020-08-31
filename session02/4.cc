#include <cassert>
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class bank_account
{
	string _name;
	int _balance;
public:
	bank_account(string name, int balance); 

	string get_name();
	int get_balance();

	void deposit_money(int money) { _balance += money; }
	void withdraw_money(int amount) { _balance -= amount; }

	void print_account()
	{
		cout << get_name() <<" has " << get_balance() << " in cash." << endl; 
	}
};
	string bank_account::get_name() { return _name; }
	int bank_account::get_balance() { return _balance; }
	bank_account::bank_account(string name, int balance) : _name(name), _balance(balance){} 

class bank
{
	vector<bank_account> bank_accounts;
public:
	void add_account(bank_account account) { bank_accounts.push_back(account); }
	void print_accounts() {
		cout << "Bank contains the following accounts:" << endl;
		for(int i = 0; i < bank_accounts.size();i++)
			bank_accounts[i].print_account(); 
	}
};

int main(int argc, char** argv)
{
	bank_account bank_account1("fnb", 1000);
	bank_account bank_account2("standard", 2000);

	assert(bank_account1.get_name() == "fnb");
	assert(bank_account2.get_name() == "standard");
	assert(bank_account1.get_balance() == 1000);
	assert(bank_account2.get_balance() == 2000);

	bank_account1.deposit_money(1);
	assert(bank_account1.get_balance() == 1001);
	bank_account1.withdraw_money(1000);
	assert(bank_account1.get_balance() == 1);
	
	bank_account1.print_account();
	bank_account2.print_account();

	bank my_bank;
	my_bank.add_account(bank_account1);
	my_bank.add_account(bank_account2);

	my_bank.print_accounts();
}
