#include <iostream>

using namespace std;

template <typename T>
class SharedPtr
{
public:
	SharedPtr(T* target) : ptr(target) { }
	~SharedPtr() { delete ptr; }
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }

private:
	T* ptr = nullptr;
	int refCount = 0;
};

class Point
{
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) { }
	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}

private:
	int xpos;
	int ypos;
};

int main()
{
	SharedPtr<Point> ptr1(new Point(1, 2));
	SharedPtr<Point> ptr2(new Point(3, 4));
	ptr1->SetPos(5, 6);
	ptr1->ShowPosition();
	ptr2->ShowPosition();
}
