#pragma once

enum class CreditLevel
{
	Level_A = 1,
	Level_B,
	Level_C,
};

class Account
{
public:
	Account();
	Account(const char* user, const int number);
	virtual ~Account();
	virtual void Deposit(int amount);
	void Withdraw(int amount);
	bool CanWithdraw(int amount) const;
	virtual void PrintAccountInfo() const;

	// getters
	char* GetUser() const;
	int GetAccountNumber() const;
	int GetBalace() const;

private:
	int mAccountNumber;
	char* mUser;
	int mBalance;
};

class NormalAccount : public Account
{
public:
	NormalAccount();
	NormalAccount(const char* user, const int number);
	NormalAccount(const char* user, const int number, const int interest);
	virtual void Deposit(int amount) override;
	virtual void PrintAccountInfo() const override;
	//setter
	void SetInterest(int interest);

private:
	int mInterest;  // 이율
};

class HighCreditAccount : public NormalAccount
{
public:
	HighCreditAccount();
	HighCreditAccount(const char* user, const int number, const CreditLevel level);
	virtual void PrintAccountInfo() const override ;

private:
	CreditLevel mCreditLevel;  // 신용 등급
};
