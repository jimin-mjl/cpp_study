#pragma once
#include "Creature.h"

namespace player
{
	enum eType
	{
		Knight = 1,
		Archer,
		Mage,
	};
}

class Player : public Creature
{
public:
	Player() : Creature(creature::Player) {}
	virtual void PrintStat();
};

class Knight : public Player
{
public:
	Knight();
};

class Archer : public Player
{
public:
	Archer();
};

class Mage : public Player
{
public:
	Mage();
};
