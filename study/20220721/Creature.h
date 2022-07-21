#pragma once

const int MAX_STR = 100;

namespace creature
{
	enum eType
	{
		Player,
		Monster,
	};
}

class Creature
{
public:
	Creature(int type)
		: mType(type), mRole(""), mHp(0), mAtt(0), mDef(0) {}

	virtual ~Creature() {}

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

	void Attack(Creature* attacked);
	void LoseHp(int damage);
	bool IsDead();
	virtual void PrintStat() = 0;

private:
	int mType;
	char mRole[MAX_STR];
	int mHp;
	int mAtt;
	int mDef;
};
