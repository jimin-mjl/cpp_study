#include <iostream>
#include "Field.h"
#include "Player.h"
#include "Monster.h"
using namespace std;

Field::~Field()
{
	if (mMonster != nullptr)
		delete mMonster;
}

void Field:: Enter(Player* player)
{
	while (player->IsDead() == false)
	{
		if (mMonster == nullptr)
			CreateMonster();

		RunBattle(player);
	}
}

void Field::CreateMonster()
{
	int role = rand() % 3;
	
	switch (role)
	{
	case monster::Slime:
		mMonster = new Slime();
		break;
	case monster::Orc:
		mMonster = new Orc();
		break;
	case monster::Ghost:
		mMonster = new Ghost();
		break;
	}

	cout << "-----------------" << endl;
	cout << "A wild " << mMonster->GetRole() << " appeared!" << endl;
	cout << "-----------------" << endl;
}

void Field::RunBattle(Player* player)
{
	while (true)
	{
		cout << "-----------------" << endl;
		player->PrintStat();
		mMonster->PrintStat();
		cout << "-----------------" << endl;

		player->Attack(mMonster);

		if (mMonster->IsDead())
		{
			delete mMonster;
			mMonster = nullptr;
			break;
		}

		mMonster->Attack(player);

		if (player->IsDead())
			break;
	}
}
