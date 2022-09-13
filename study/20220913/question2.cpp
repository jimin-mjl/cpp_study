class Point
{
	friend Point operator~(const Point& po);

public:
	Point(int xval, int yval)
		: x(xval)
		, y(yval)
	{

	}
	Point operator-()
	{
		return Point(-x, -y);
	}

private:
	int x;
	int y;
};

Point operator~(const Point& po)
{
	return Point(po.y, po.x);
}
