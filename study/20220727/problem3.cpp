#include <iostream>
using namespace std;

#pragma warning( disable : 4996 )

namespace position
{
	enum Position
	{
		Clerk,
		Senior,
		Assist,
		Manager,
	};

	const char* GetPosition(int pos)
	{
		switch (pos)
		{
		case Clerk:
			return "사원";
		case Senior:
			return "주임";
		case Assist:
			return "대리";
		case Manager:
			return "매니저";
		}
	}
}

class NameCard
{
public:
	NameCard(const char* name, const char* company, const char* phone, int pos)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];

		strcpy(this->name, name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);

		this->position = pos;
	}
	void ShowNameCardInfo()
	{
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: " << position::GetPosition(position) << endl;
	}

private:
	char* name;
	char* company;
	char* phone;
	int position;
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", position::Clerk);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", position::Senior);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", position::Assist);

	manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
}
