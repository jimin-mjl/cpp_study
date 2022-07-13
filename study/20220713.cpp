#include <iostream>
using namespace std;

void IncreaseOne(int& num);
void InverseNum(int& num);
void SwapPtr(int*& a, int*& b);

int main()
{
	// Q1 
	int number = 3;
	IncreaseOne(number);
	InverseNum(number);
	cout << number << endl; // -4

	// Q2
	int num1 = 5;
	int num2 = 10;
	int* ptr1 = &num1;
	int* ptr2 = &num2;
	SwapPtr(ptr1, ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;  // 10 5

	// Q3
	const int num3 = 12;
	const int* ptr3 = &num3;
	const int*& ref3 = ptr3;
	cout << *ptr3 << endl;  // 12
	cout << *ref3 << endl;  // 12

	// Example 1
	int num4 = 12;
	int* ptr4 = &num4;  // pointer of num4
	int** pptr4 = &ptr4;  // pointer of ptr4

	int& ref = num4;
	int*& pref = ptr4;
	int**& ppref = pptr4;

	cout << ref << endl;
	cout << *pref << endl;  // *pref = *ptr4 = 12
	cout << **ppref << endl;  // **ppref = **pptr4 = *ptr4 = 12
}

void IncreaseOne(int& num)
{
	num++;
}

void InverseNum(int& num)
{
	num = -num;
}

void SwapPtr(int*& x, int*& y)
{
	int* temp = x;
	x = y;
	y = temp;
}
