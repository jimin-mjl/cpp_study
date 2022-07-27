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
			return "���";
		case Senior:
			return "����";
		case Assist:
			return "�븮";
		case Manager:
			return "�Ŵ���";
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
		cout << "�̸�: " << name << endl;
		cout << "ȸ��: " << company << endl;
		cout << "��ȭ��ȣ: " << phone << endl;
		cout << "����: " << position::GetPosition(position) << endl;
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
