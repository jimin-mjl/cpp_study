#include <iostream>
using namespace std;

class Point
{
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;

	}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	void SetX(int x) { xpos = x; }
	void SetY(int y) { ypos = y; }
	int GetX() const { return xpos; }
	int GetY() const { return ypos; }

private:
	int xpos;
	int ypos;
};

class Circle
{
public:
	Circle() : center(nullptr), radius(0)
	{

	}
	void SetCenter(int x, int y)
	{
		if (center == nullptr)
		{
			center = new Point();
			center->Init(x, y);
		}
		else
		{
			center->SetX(x);
			center->SetY(y);
		}
	}
	void SetRadius(int r) { radius = r; }
	int GetRadius() const { return radius; }
	void ShowCenterInfo() const { center->ShowPointInfo(); }

private:
	Point* center;
	int radius;
};

class Ring
{
public:
	Ring() : innerCircle(nullptr), outerCircle(nullptr)
	{

	}
	void Init(int inx, int iny, int inr, int oux, int ouy, int our)
	{
		innerCircle = new Circle();
		innerCircle->SetCenter(inx, iny);
		innerCircle->SetRadius(inr);

		outerCircle = new Circle();
		outerCircle->SetCenter(oux, ouy);
		outerCircle->SetRadius(our);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		cout << "radius: " << innerCircle->GetRadius() << endl;
		innerCircle->ShowCenterInfo();

		cout << "Outer Circle Info..." << endl;
		cout << "radius: " << outerCircle->GetRadius() << endl;
		outerCircle->ShowCenterInfo();
	}

private:
	Circle* innerCircle;
	Circle* outerCircle;
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
}
