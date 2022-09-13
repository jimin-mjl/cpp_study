#include <iostream>

using namespace std;

class Point
{
	friend ostream& operator<<(ostream& os, const Point& po);
	friend istream& operator>>(istream& is, Point& po);

public:
	Point()
		: x(0)
		, y(0)
	{
	}

private:
	int x;
	int y;
};

ostream& operator<<(ostream& os, const Point& po)
{
	os << "[" << po.x << ", " << po.y << "]" << endl;
	return os;
}

istream& operator>>(istream& is, Point& po)
{
	is >> po.x >> po.y;
	return is;
}

int main()
{
	Point p1;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> p1;
	cout << p1;

	Point p2;
	cout << "x, y 좌표 순으로 입력: ";
	cin >> p2;
	cout << p2;
}
