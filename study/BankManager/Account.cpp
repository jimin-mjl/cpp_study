#include <iostream>
#include <string>

#include "Account.h"

Account::Account()
	: mAccountNumber(0)
	, mUser(nullptr)
	, mBalance(0)
{
}

Account::Account(const char* user, const int number)
	: mAccountNumber(number)
	, mBalance(0)
{
	size_t size = strlen(user) + 1;
	mUser = new char[size];
	strcpy_s(mUser, size, user);
}

Account::~Account()
{
	if (mUser)
	{
		delete[] mUser;
	}
}

void Account::Deposit(int amount)
{
	mBalance += amount;
}

void Account::Withdraw(int amount)
{
	if (CanWithdraw(amount))
	{
		mBalance -= amount;
	}
}

bool Account::CanWithdraw(int amount) const
{
	if (mBalance >= amount)
	{
		return true;
	}

	return false;
}

void Account::PrintAccountInfo() const
{
	std::cout << "User: " << mUser << std::endl;
	std::cout << "Account Number: " << mAccountNumber << std::endl;
	std::cout << "Balance: " << mBalance << std::endl;
}

char* Account::GetUser() const
{
	return mUser;
}

int Account::GetAccountNumber() const
{
	return mAccountNumber;
}

int Account::GetBalace() const
{
	return mBalance;
}

NormalAccount::NormalAccount()
	: Account()
	, mInterest(0)
{
}

NormalAccount::NormalAccount(const char* user, const int number)
	: Account(user, number)
	, mInterest(0)
{
}

NormalAccount::NormalAccount(const char* user, const int number, const int interest)
	: Account(user, number)
	, mInterest(interest)
{
}

void NormalAccount::Deposit(int amount)
{
	amount += (amount * (mInterest / 100));
	Account::Deposit(static_cast<int>(amount));
}

void NormalAccount::PrintAccountInfo() const
{
	Account::PrintAccountInfo();
	std::cout << "Interest: " << mInterest << std::endl;

}

void NormalAccount::SetInterest(int interest)
{
	mInterest = interest;
}

HighCreditAccount::HighCreditAccount()
	: NormalAccount()
	, mCreditLevel(CreditLevel::Level_C)
{
}

HighCreditAccount::HighCreditAccount(const char* user, const int number, const CreditLevel level)
	: NormalAccount(user, number)
	, mCreditLevel(level)
{
	switch (level)
	{
	case CreditLevel::Level_A:
		SetInterest(7);
		break;
	case CreditLevel::Level_B:
		SetInterest(4);
		break;
	case CreditLevel::Level_C:
		SetInterest(2);
		break;
	}
}

void HighCreditAccount::PrintAccountInfo() const
{
	NormalAccount::PrintAccountInfo();
	std::cout << "Credit Level: " << static_cast<int>(mCreditLevel) << std::endl;
}
