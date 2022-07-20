#pragma once
#include "Entity.h"

class Lobby
{
public:
	void PrintMsg(const char* msg);
	void PrintStat(Player* player, Monster* monster);
	void Enter();
	void RunBattle(Player* player, Monster* monster);
	Player* CreatePlayer(int role);
	Monster* CreateMonster(int role);
};
