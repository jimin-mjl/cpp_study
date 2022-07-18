#include <iostream>
using namespace std;

struct Point
{
	int xpos;
	int ypos;

	void MovePos(int x, int y);  // ���� ��ǥ �̵�
	void AddPoint(const Point& pos);  // ���� ��ǥ�� ����
	void ShowPosition();  // ���� x, y ��ǥ ���� ���
};

int main()
{
	Point pos1 = { 12, 4 };
	Point pos2 = { 20, 30 };

	pos1.MovePos(-7, 10);
	pos1.ShowPosition();  // [5, 14]

	pos1.AddPoint(pos2);
	pos1.ShowPosition();  // [25, 44]
}

inline void Point::MovePos(int x, int y)
{
	xpos += x;
	ypos += y;
}

inline void Point::AddPoint(const Point& pos)
{
	xpos += pos.xpos;
	ypos += pos.ypos;
}

inline void Point::ShowPosition()
{
	cout << "[ " << xpos << ", " << ypos << " ]" << endl;
}
