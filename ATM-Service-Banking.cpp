#include <iostream>

using namespace std;

// global variable
int balance = 10000;

void get_pin(int pin);
void print_menu();
void get_choise(int& choise);


int main()
{
	int pin = 0;
	int choise = 0;

	cout << "************************************Welcome to Al-Ahly ATM Service Banking***********************************\n\n\n\n";
	// call functions
	get_pin(pin);
	get_choise(choise);

	return 0;
}

// function to read pin from user and check pin
void get_pin(int pin)
{
	cout << "Enter your pin: \n";
	cin >> pin;
	
	while (pin != 1535)
	{
		cout << "The pin entered error, try again: \n";
		cin >> pin;
	}
}

//function to print menue 
void print_menu()
{
	cout << "1- Check Account \n";
	cout << "2- Withdraw Cash \n";
	cout << "3- Deposit Cash \n";
	cout << "4- Quit \n";
}

// function to print balance for account then back to function get_choise again
void check_account(int choise)
{
	cout << "Your Current Blance: " << balance << endl;
	get_choise(choise);
}

// funtcion to read withdraw fom user and Subtract from balance and call function check_account
void wihdraw_cash(int choise)
{
	int withdraw = 0;
	cout << "Enter an amount to wihdraw: \n";
	cin >> withdraw;
	
	while (withdraw > balance)
	{
		cout << "Your amount is not enough, try again: \n";
		cin >> withdraw;
	}

		balance -= withdraw;
	
		check_account(choise);
}

// function to read deposit from user and subtract from balance and call function check_account
void deposit_cash(int choise)
{
	int deposit = 0;
	cout << "Enter an amount to deposit: \n";
	cin >> deposit;

	balance += deposit;

	check_account(choise);
}

// function to quit from the program
void quit()
{
	cout << "\n\n************************************Thank you for using our service***********************************\n\n\n\n";
	exit(0);
}

// function to read choise from user and call function Of the four, according to the user's choice
void get_choise(int &choise)
{
	print_menu();
	cout << "Chose from the menu: \n";
	cin >> choise;

	while (choise != 1 && choise != 2 && choise != 3 && choise != 4)
	{
		print_menu();
		cout << "please enter number from 1 to 4 only: \n";
		cin >> choise;
	}
	
	if (choise == 1)
		check_account(choise);
	else if (choise == 2)
		wihdraw_cash(choise);
	else if (choise == 3)
		deposit_cash(choise);
	else
		quit();
}