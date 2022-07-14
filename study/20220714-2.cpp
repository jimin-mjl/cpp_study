// using new & delete

#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& AddPoints(const Point& p1, const Point& p2);

int main()
{
	Point* point1 = new Point;
	point1->xpos = 3;
	point1->ypos = 5;
	Point* point2 = new Point;
	point2->xpos = 2;
	point2->ypos = 4;

	Point& ref1 = *point1;
	Point& ref2 = *point2;

	Point& ref3 = AddPoints(ref1, ref2);
	cout << ref3.xpos << endl;
	cout << ref3.ypos << endl;

	delete point1;
	delete point2;
	delete& ref3;
}

Point& AddPoints(const Point& p1, const Point& p2)
{
	int x = p1.xpos + p2.xpos;
	int y = p1.ypos + p2.ypos;

	Point* point = new Point;
	point->xpos = x;
	point->ypos = y;

	return *point;
}
