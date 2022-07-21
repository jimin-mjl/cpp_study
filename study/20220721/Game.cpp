#include <iostream>
#include "Field.h"
#include "Game.h"
#include "Player.h"
using namespace std;

Game::~Game()
{
	if (mPlayer != nullptr)
		delete mPlayer;

	if (mField != nullptr)
		delete mField;
}

void Game::Init()
{
	srand((unsigned int)time(nullptr));

	if (mField == nullptr)
		mField = new Field();
}

void Game::Update()
{
	if (mPlayer == nullptr)
		CreatePlayer();

	if (mField == nullptr)
		Init();
	
	mField->Enter(mPlayer);

	if (mPlayer->IsDead())
	{
		delete mPlayer;
		mPlayer = nullptr;
	}
}

void Game::CreatePlayer()
{
	while (mPlayer == nullptr)
	{
		cout << "---------------------------" << endl;
		cout << "Select your job: Knight(1) Archer(2) Mage(3)" << endl;
		cout << "> ";
	
		int role;
		cin >> role;

		switch (role)
		{
		case player::Knight:
			mPlayer = new Knight();
			break;
		case player::Archer:
			mPlayer = new Archer();
			break;
		case player::Mage:
			mPlayer = new Mage();
			break;
		}
	}

	cout << "-----------------" << endl;
	cout << "Creating " << mPlayer->GetRole() << "... Done!" << endl;
	cout << "-----------------" << endl;
}
