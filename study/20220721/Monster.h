#pragma once
#include "Creature.h"

namespace monster
{
	enum Monster
	{
		Slime = 0,
		Orc,
		Ghost,
	};
}

class Monster : public Creature
{
public:
	Monster() : Creature(creature::Monster) {}
	virtual void PrintStat();
};

class Slime : public Monster
{
public:
	Slime();
};

class Orc : public Monster
{
public:
	Orc();
};

class Ghost : public Monster
{
public:
	Ghost();
};
