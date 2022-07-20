#pragma once

class Entity
{
public:
	virtual ~Entity();

	// setter
	void SetRole(const char* str);
	void SetHp(int hp);
	void SetAttack(int att);
	void SetDefense(int def);

	// getter
	const char* GetRole();
	int GetHp();
	int GetAttack();
	int GetDefense();

	void Attack(Entity* attacked);
	void LoseHp(int damage);
	bool IsDead();


private:
	char mRole[30];
	int mHp;
	int mAtt;
	int mDef;
};

class Player : public Entity
{
public:
	Player();

public:
	enum eRole
	{
		Knight = 1,
		Archer,
		Mage,
	};
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

class Monster : public Entity
{
public:
	enum eRole
	{
		Slime,
		Org,
		Ghost,
	};
};

class Slime : public Monster
{
public:
	Slime();
};

class Org : public Monster
{
public:
	Org();
};

class Ghost : public Monster
{
public:
	Ghost();
};
