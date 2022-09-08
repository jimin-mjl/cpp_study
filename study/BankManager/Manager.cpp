#include <iostream>
#include <string>

#include "Manager.h"
#include "Account.h"

Manager::Manager()
	: mAccountCount(0)
{
}

void Manager::PrintMsg(const char* msg) const
{
	std::cout << msg << std::endl;
}

void Manager::CreateAccount()
{
	std::cout << std::endl;
	PrintMsg("[Create Account]");
	PrintMsg("Choose account type.");
	PrintMsg("1. Normal Account 2. High Credit Account");
	std::cout << "Select: ";
	int type;
	std::cin >> type;

	std::cout << "Your name: ";
	std::string name;
	std::cin >> name;

	std::cout << "Account Number: ";
	int number;
	std::cin >> number;

	Account& acc = createAccount(name.c_str(), number, static_cast<AccountType>(type));

	PrintMsg("Your Account Created.");
	PrintAccountInfo(acc);
}

void Manager::PrintAccountInfo(const Account& acc) const
{
	std::cout << std::endl;
	PrintMsg("[Account Info]");
	acc.PrintAccountInfo();
	std::cout << std::endl;
}

void Manager::Deposit()
{
	std::cout << std::endl;
	PrintMsg("[Deposit]");

	std::cout << "Account number: ";
	int number;
	std::cin >> number;

	std::cout << "Amount: ";
	int amount;
	std::cin >> amount;

	Account* acc = deposit(number, amount);

	if (acc == nullptr)
	{
		std::cout << std::endl;
		PrintMsg("No account matches the given number.");
		return;
	}

	PrintAccountInfo(*acc);
}

void Manager::Withdraw()
{
	PrintMsg("[Withdraw]");

	std::cout << "Account number: ";
	int number;
	std::cin >> number;

	std::cout << "Amount: ";
	int amount;
	std::cin >> amount;

	Account* acc = withdraw(number, amount);
	if (acc == nullptr)
	{
		std::cout << std::endl;
		PrintMsg("No account matches the given number or balance not enough.");
		return;
	}

	PrintAccountInfo(*acc);
}

void Manager::PrintAllAccountInfo()
{
	std::cout << std::endl;
	PrintMsg("[Browse Accounts]");

	for (int i = 0; i < mAccountCount; i++)
	{
		mAccountList[i]->PrintAccountInfo();
		std::cout << std::endl;
	}
}

Account& Manager::createAccount(const char* name, const int number, AccountType type)
{
	int input;
	Account* acc = nullptr;

	switch (type)
	{
	case AccountType::NormalAccount:
		std::cout << "Interest: ";
		std::cin >> input;
		acc = new NormalAccount(name, number, input);
		break;
	case AccountType::HighCreditAccount:
		std::cout << "Credit Level: ";
		std::cin >> input;
		acc = new HighCreditAccount(name, number, static_cast<CreditLevel>(input));
		break;
	default:
		acc = new Account(name, number);
		break;
	}
	
	mAccountList[mAccountCount++] = acc;
	return *acc;
}

Account* Manager::deposit(const int id, const int amount)
{
	Account* acc = getAccountByID(id);

	if (acc)
	{
		acc->Deposit(amount);
	}

	return acc;
}

Account* Manager::withdraw(const int id, const int amount)
{
	Account* acc = getAccountByID(id);

	if (acc && acc->CanWithdraw(amount))
	{
		acc->Withdraw(amount);
		return acc;
	}

	return nullptr;
}

bool Manager::canWithdraw(const int amount)
{
	return false;
}

Account* Manager::getAccountByID(const int id)
{
	for (int i = 0; i < mAccountCount; i++)
	{
		if (mAccountList[i]->GetAccountNumber() == id)
		{
			return mAccountList[i];
		}
	}

	return nullptr;
}
