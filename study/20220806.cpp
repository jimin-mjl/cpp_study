#include <iostream>
using namespace std;

enum class Position
{
	Clerk,
	Senior,
	Assist,
	Manager,
};

const char* GetPositionName(Position position)
{
	switch (position)
	{
	case Position::Clerk:
		return "Clerk";
	case Position::Senior:
		return "Senior";
	case Position::Assist:
		return "Assist";
	case Position::Manager:
		return "Manager";
	default:
		return "Invalid value";
	}
}

class NameCard
{
public:
	NameCard(const char* name, const char* company, const char* phone, Position position)
		: mPosition(position)
	{
		auto nameSize = strlen(name) + 1;
		mName = new char[nameSize];
		strcpy_s(mName, nameSize, name);

		auto companySize = strlen(company) + 1;
		mCompany = new char[companySize];
		strcpy_s(mCompany, companySize, company);

		auto phoneSize = strlen(phone) + 1;
		mPhone = new char[phoneSize];
		strcpy_s(mPhone, phoneSize, phone);
	}
	NameCard(const NameCard& nc) : mPosition(nc.mPosition)
	{
		auto nameSize = strlen(nc.mName) + 1;
		mName = new char[nameSize];
		strcpy_s(mName, nameSize, nc.mName);

		auto companySize = strlen(nc.mCompany) + 1;
		mCompany = new char[companySize];
		strcpy_s(mCompany, companySize, nc.mCompany);

		auto phoneSize = strlen(nc.mPhone) + 1;
		mPhone = new char[phoneSize];
		strcpy_s(mPhone, phoneSize, nc.mPhone);
	}
	virtual ~NameCard()
	{
		delete[] mName;
		delete[] mCompany;
		delete[] mPhone;
	}
	void ShowNameCardInfo()
	{
		cout << "Name: " << mName << endl;
		cout << "Company: " << mCompany << endl;
		cout << "Phone Number: " << mPhone << endl;
		cout << "Position: " << GetPositionName(mPosition) << endl;
	}

private:
	char* mName;
	char* mCompany;
	char* mPhone;
	Position mPosition;
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", Position::Clerk);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", Position::Senior);
	NameCard clerkCopy = manClerk;
	NameCard seniorCopy = manSenior;

	clerkCopy.ShowNameCardInfo();
	seniorCopy.ShowNameCardInfo();
}
