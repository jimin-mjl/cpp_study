#include <string>
#include "Creature.h"

void Creature::SetRole(const char* str)
{
	strcpy_s(mRole, str);
}

void Creature::SetHp(int hp)
{
	mHp = hp;
}

void Creature::SetAttack(int att)
{
	mAtt = att;
}

void Creature::SetDefense(int def)
{
	mDef = def;
}

const char* Creature::GetRole()
{
	return mRole;
}

int Creature::GetHp()
{
	return mHp;
}

int Creature::GetAttack()
{
	return mAtt;
}

int Creature::GetDefense()
{
	return mDef;
}

void Creature::LoseHp(int damage)
{
	mHp -= damage;
	if (mHp < 0)
		mHp = 0;
}

void Creature::Attack(Creature* attacked)
{
	int damage = mAtt - attacked->GetDefense();
	if (damage <= 0)
		damage = 0;

	attacked->LoseHp(damage);
}

bool Creature::IsDead()
{
	return mHp == 0;
}
