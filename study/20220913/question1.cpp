#include <iostream>

using namespace std;

class Point
{
	friend Point operator-(const Point& p1, const Point& p2);

public:
	Point(int xval, int yval)
		: x(xval)
		, y(yval)
	{

	}
	Point& operator+=(const Point& po)
	{
		x += po.x;
		y += po.y;
		return *this;
	}
	Point& operator-=(const Point& po)
	{
		x -= po.x;
		y -= po.y;
		return *this;
	}
	bool operator==(const Point& po)
	{
		if (x == po.x && y == po.y)
			return true;
		return false;
	}
	bool operator!=(const Point& po)
	{
		return !(this->operator==(po));
	}

private:
	int x;
	int y;
};

Point operator-(const Point& p1, const Point& p2)
{
	return Point(p1.x - p2.x, p1.y - p2.y);
}
