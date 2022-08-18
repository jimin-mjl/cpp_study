#include <iostream>
using namespace std;

class Friend
{
public:
	Friend(const char* name, int age)
		: mAge(age)
	{
		size_t size = strlen(name) + 1;
		mName = new char[size];
		strcpy_s(mName, size, name);
	}
	virtual ~Friend()
	{
		cout << "Bye Friend" << endl;

		if (mName)
		{
			delete mName;
		}
	}
	void PrintFriendInfo()
	{
		cout << "Name:" << mName << endl;
		cout << "Age:" << mAge << endl;
	}

private:
	char* mName;
	int mAge;
};

class FriendAddress : public Friend
{
public:
	FriendAddress(const char* name, int age, const char* address, const char* phone)
		: Friend(name, age)
	{
		size_t addrSize = strlen(address) + 1;
		size_t phoneSize = strlen(phone) + 1;

		mAddress = new char[addrSize];
		mPhone = new char[phoneSize];

		strcpy_s(mAddress, addrSize, address);
		strcpy_s(mPhone, phoneSize, phone);
	}
	virtual ~FriendAddress()
	{
		cout << "Bye Friend Address" << endl;

		if (mAddress)
		{
			delete mAddress;
		}

		if (mPhone)
		{
			delete mPhone;
		}
	}
	void PrintFriendAddress()
	{
		PrintFriendInfo();
		cout << "Address: " << mAddress << endl;
		cout << "Phone: " << mPhone << endl;
	}

private:
	char* mAddress;
	char* mPhone;
};

int main()
{
	FriendAddress fa("Grace", 20, "Napier churchroad 53", "010-1111-2222");
	fa.PrintFriendAddress();
}