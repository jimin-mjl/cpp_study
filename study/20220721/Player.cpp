#include <iostream>
#include "Player.h"
using namespace std;

Knight::Knight()
{
	SetHp(100);
	SetRole("knight");
	SetAttack(20);
	SetDefense(3);
}

Archer::Archer()
{
	SetHp(90);
	SetRole("archer");
	SetAttack(16);
	SetDefense(5);
}

Mage::Mage()
{
	SetHp(80);
	SetRole("mage");
	SetAttack(13);
	SetDefense(7);
}

void Player::PrintStat()
{
	cout << "Your HP: " << GetHp() << endl;
}
