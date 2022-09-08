#pragma once

class Account;

constexpr int MAX_ACCOUNT_COUNT = 100;

enum class AccountType
{
	NormalAccount = 1,
	HighCreditAccount,
};

class Manager
{
public:
	Manager();
	void PrintMsg(const char* msg) const;
	void CreateAccount();
	void PrintAccountInfo(const Account& acc) const;
	void Deposit();
	void Withdraw();
	void PrintAllAccountInfo();

private:
	Account& createAccount(const char* name, const int number, AccountType type);
	Account* deposit(const int id, const int amount);
	Account* withdraw(const int id, const int amount);
	bool canWithdraw(const int amount);
	Account* getAccountByID(const int id);

private:
	Account* mAccountList[MAX_ACCOUNT_COUNT] = {};
	int mAccountCount;
};

