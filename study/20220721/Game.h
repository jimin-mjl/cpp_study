#pragma once

class Player;
class Field;

class Game
{
public:
	Game() : mPlayer(nullptr), mField(nullptr) {}
	virtual ~Game();
	void Init();
	void Update();
	void CreatePlayer();

private:
	Player* mPlayer;
	Field* mField;
};
