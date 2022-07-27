#include <iostream>
using namespace std;

class BargainResult
{
public:
	BargainResult(int count, int money) : mAppleCount(count), mLeftover(money)
	{

	}

	int GetAppleCount() const { return mAppleCount; }

	int GetLeftover() const { return mLeftover; }

private:
	int mAppleCount;
	int mLeftover;  // 거스름돈 
};

class Seller
{
public:
	Seller() : mStock(10), mAPPLE_PRICE(1000), mMoney(0) { }

	BargainResult* Sell(int money)
	{
		int count = money / mAPPLE_PRICE;
		int totalApples;
		int leftover;

		if (mStock >= count)
			totalApples = count;
		else
			totalApples = mStock;

		mStock -= totalApples;
		mMoney += mAPPLE_PRICE * totalApples;
		leftover = money - (mAPPLE_PRICE * totalApples);

		return new BargainResult(totalApples, leftover);
	}

private:
	int mAPPLE_PRICE;
	int mStock;
	int mMoney;
};

class Customer
{
public:
	Customer() : mMoney(0), mApple(0)
	{

	}

	bool SetMoney(int money)
	{
		if (money < 0)
		{
			cout << "돈은 0보다 많아야 합니다" << endl;
			return false;
		}

		mMoney = money;
		return true;
	}

	void Buy(Seller* seller)
	{
		BargainResult* result = seller->Sell(mMoney);
		mApple += result->GetAppleCount();
		mMoney = result->GetLeftover();
		cout << "사과를 " << result->GetAppleCount() << "개 구매했습니다" << endl;
		delete result;
	}

private:
	int mMoney;
	int mApple;
};

int main()
{
	Seller seller;
	Customer customer;

	customer.SetMoney(10000);
	customer.Buy(&seller);
}
