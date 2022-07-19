#pragma once

const int MAX_STR = 100;

class Printer
{
private:
	char mText[MAX_STR];

public:
	void SetString(const char* str);
	void ShowString();
};
