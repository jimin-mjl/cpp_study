#include "Game.h"

int main()
{
	Game game;
	game.Init();

	while (true)
		game.Update();
}
