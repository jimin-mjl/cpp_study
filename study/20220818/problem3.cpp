#include <iostream>
using namespace std;

class Rectangle
{
public:
	Rectangle(int width, int height)
		: mWidth(width)
		, mHeight(height)
	{

	}
	void PrintAreaInfo()
	{
		cout << "Area: " << mWidth * mHeight << endl;
	}

private:
	int mWidth;
	int mHeight;
};

class Square : public Rectangle
{
public:
	Square(int width)
		: Rectangle(width, width)
	{

	}
};

int main()
{
	Rectangle rec(4, 3);
	rec.PrintAreaInfo();

	Square sqr(7);
	sqr.PrintAreaInfo();
}