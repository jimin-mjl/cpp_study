#include <iostream>
#include "calculator.h"
using namespace std;

void Calculator::Init()
{
	mAddCount = 0;
	mMinCount = 0;
	mMulCount = 0;
	mDivCount = 0;
}

void Calculator::ShowOpCount()
{
	cout << "µ¡¼À: " << mAddCount << " »¬¼À: " << mMinCount << " °ö¼À: " << mMulCount << " ³ª´°¼À: " << mDivCount << endl;
}

float Calculator::Add(float a, float b)
{
	mAddCount++;
	return a + b;
}

float Calculator::Min(float a, float b)
{
	mMinCount++;
	return a - b;
}

float Calculator::Mul(float a, float b)
{
	mMulCount++;
	return a * b;
}

float Calculator::Div(float a, float b)
{
	mDivCount++;
	return a / b;
}
