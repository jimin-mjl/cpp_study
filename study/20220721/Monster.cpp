#include <iostream>
#include "Monster.h"
using namespace std;

Slime::Slime()
{
	SetHp(10);
	SetRole("slime");
	SetAttack(10);
	SetDefense(3);
}

Orc::Orc()
{
	SetHp(30);
	SetRole("org");
	SetAttack(20);
	SetDefense(10);
}

Ghost::Ghost()
{
	SetHp(20);
	SetRole("ghost");
	SetAttack(15);
	SetDefense(5);
}

void Monster::PrintStat()
{
	cout << GetRole() << " HP: " << GetHp() << endl;
}
