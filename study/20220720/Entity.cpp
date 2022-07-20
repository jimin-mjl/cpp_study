#include "Entity.h"

virtual Entity::~Entity() {}

void Entity::SetRole(const char* str)
{
	strcpy(mRole, str);
}

void Entity::SetHp(int hp)
{
	mHp = hp;
}

void Entity::SetAttack(int att)
{
	mAtt = att;
}

void Entity::SetDefense(int def)
{
	mDef = def;
}

const char* Entity::GetRole()
{
	return mRole;
}

int Entity::GetHp()
{
	return mHp;
}

int Entity::GetAttack()
{
	return mAtt;
}

int Entity::GetDefense()
{
	return mDef;
}

void Entity::LoseHp(int damage)
{
	mHp -= damage;
	if (mHp < 0)
		mHp = 0;
}

void Entity::Attack(Entity* attacked)
{
	int damage = mAtt - attacked->GetDefense();
	if (damage <= 0)
		damage = 0;

	attacked->LoseHp(damage);
}

bool Entity::IsDead()
{
	return mHp == 0;
}

Player::Player()
{
	SetHp(100);
}

Knight::Knight()
{
	SetRole("knight");
	SetAttack(20);
	SetDefense(3);
}

Archer::Archer()
{
	SetRole("archer");
	SetAttack(16);
	SetDefense(5);
}

Mage::Mage()
{
	SetRole("mage");
	SetAttack(13);
	SetDefense(7);
}

Slime::Slime()
{
	SetRole("slime");
	SetHp(10);
	SetAttack(10);
	SetDefense(3);
}

Org::Org()
{
	SetRole("org");
	SetHp(30);
	SetAttack(20);
	SetDefense(10);
}

Ghost::Ghost()
{
	SetRole("ghost");
	SetHp(20);
	SetAttack(15);
	SetDefense(5);
}
