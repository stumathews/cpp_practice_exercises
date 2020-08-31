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
	void deposit_money(int amount, string account) {
		for(int i = 0; i < bank_accounts.size();i++) {
			if(bank_accounts[i].get_name() == account)
				bank_accounts[i].deposit_money(amount);
		}	
	}
	void withdraw_money(int amount, string account){
		for(int i = 0; i < bank_accounts.size();i++) {
			if(bank_accounts[i].get_name() == account)
				bank_accounts[i].withdraw_money(amount);
		}
	}
};

int main(int argc, char** argv)
{
	bank_account fnb_account("fnb", 1000);
	bank_account standard_account("standard", 2000);

	assert(fnb_account.get_name() == "fnb");
	assert(standard_account.get_name() == "standard");
	assert(fnb_account.get_balance() == 1000);
	assert(standard_account.get_balance() == 2000);

	fnb_account.deposit_money(1);
	fnb_account.withdraw_money(1000);
	
	assert(fnb_account.get_balance() == 1);
	
	fnb_account.print_account();
	standard_account.print_account();

	bank my_bank;
	my_bank.add_account(fnb_account);
	my_bank.add_account(standard_account);

	my_bank.deposit_money(12, "fnb");
	my_bank.withdraw_money(3, "fnb");

	my_bank.print_accounts();
}
