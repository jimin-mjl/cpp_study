#include <iostream>

#include "Account.h"
#include "Manager.h"

void PrintMsg(const char* msg)
{
	std::cout << msg << std::endl;
}

int main()
{
	Manager manager; 

	while (true)
	{
		PrintMsg("-----Menu-----");
		PrintMsg("1. Create Account");
		PrintMsg("2. Deposit");
		PrintMsg("3. Withdraw");
		PrintMsg("4. Browes All Account Info");
		PrintMsg("5. Exit Program");
		std::cout << std::endl;
		std::cout << "Select: ";
		int choice;
		std::cin >> choice;

		if (choice == 5)
		{
			return 0;
		}

		switch (choice)
		{
		case 1:
			manager.CreateAccount();
			break;
		case 2:
			manager.Deposit();
			break;
		case 3:
			manager.Withdraw();
			break;
		case 4:
			manager.PrintAllAccountInfo();
			break;
		default:
			break;
		}

		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}
