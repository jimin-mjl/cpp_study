#pragma once

class Monster;
class Player;

class Field
{
public:
	Field() : mMonster(nullptr) {}
	virtual ~Field();
	void Enter(Player* player);
	void CreateMonster();
	void RunBattle(Player* player);

private:
	Monster* mMonster;
};
