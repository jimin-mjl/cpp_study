#pragma once

class Calculator
{
private:
	int mAddCount;
	int mMinCount;
	int mMulCount;
	int mDivCount;

public:
	void Init();
	void ShowOpCount();
	float Add(float a, float b);
	float Min(float a, float b);
	float Mul(float a, float b);
	float Div(float a, float b);
};
