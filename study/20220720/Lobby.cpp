#include <iostream>
#include "Entity.h"
#include "Lobby.h"
using namespace std;

void Lobby::PrintMsg(const char* msg)
{
	cout << msg << endl;
}

void Lobby::PrintStat(Player* player, Monster* monster)
{
	PrintMsg("---------------------");
	cout << "You: " << player->GetHp() << " " << monster->GetRole() << ": " << monster->GetHp() << endl;
}

void Lobby::Enter()
{
	srand((unsigned int)time(nullptr));

	PrintMsg("---------------------");
	PrintMsg("Select your role: knight(1) / archer(2) / mage(3)");
	PrintMsg("> ");

	int input;
	cin >> input;

	Player* player = CreatePlayer(input);
	while (player->IsDead())
	{
		int monsterRole = rand() % 3;
		Monster* monster = CreateMonster(monsterRole);

		RunBattle(player, monster);
	}
}

void Lobby::RunBattle(Player* player, Monster* monster)
{
	while (true)
	{
		player->Attack(monster);
		if (monster->IsDead())
		{
			PrintMsg("---------------------");
			cout << monster->GetRole() << " is Dead!" << endl;
			break;
		}

		monster->Attack(player);
		if (player->IsDead())
		{
			PrintMsg("---------------------");
			cout << "You are Dead... Game Over!" << endl;
			break;
		}

		PrintStat(player, monster);
	}
}

Player* Lobby::CreatePlayer(int role)
{
	Player* player;

	switch (role)
	{
	case Player::Knight:
		player = new Knight;
		break;
	case Player::Archer:
		player = new Archer;
		break;
	case Player::Mage:
		player = new Mage;
		break;
	default:
		break;
	}

	PrintMsg("---------------------");
	cout << "Creating " << player->GetRole() << "... Done!" << endl;
	return player;
}

Monster* Lobby::CreateMonster(int role)
{
	Monster* monster;

	switch (role)
	{
	case Monster::Slime:
		monster = new Slime;
		break;
	case Monster::Org:
		monster = new Org;
		break;
	case Monster::Ghost:
		monster = new Ghost;
		break;
	default:
		break;
	}

	PrintMsg("---------------------");
	cout << "A wild " << monster->GetRole() << " appeared!" << endl;
	return monster;
}
