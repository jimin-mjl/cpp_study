// Snail Question

#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;
int board[MAX][MAX] = {};
int length;

int diffX[] = { 1, 0, -1, 0 };
int diffY[] = { 0, 1, 0, -1 };

enum Direction
{
	RIGHT,
	DOWN,
	LEFT,
	UP,
};

void PrintBoard()
{
	for (int y = 0; y < length; y++)
	{
		for (int x = 0; x < length; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

bool CanGo(int x, int y)
{
	if (x >= length || x < 0)
	{
		return false;
	}
	else if (y >= length || y < 0)
	{
		return false;
	}
	else if (board[y][x] != 0)
	{
		return false;
	}

	return true;
}

void SetBoard()
{
	int x = 0;
	int y = 0;
	int inc = 1;
	int dir = 0;

	while (true)
	{
		board[y][x] = inc;

		if (board[y][x] == length * length)
			break;

		int nextX = x + diffX[dir];
		int nextY = y + diffY[dir];

		if (CanGo(nextX, nextY))
		{
			x = nextX;
			y = nextY;
		}
		else
		{
			dir = (dir + 1) % 4;
			x += diffX[dir];
			y += diffY[dir];
		}

		inc++;
	}
}

int main()
{
	cin >> length;
	SetBoard();
	PrintBoard();
}
