#include <iostream>
#include "printer.h"
using namespace std;

void Printer::SetString(const char* str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		mText[i] = str[i];
		i++;
	}
	mText[i] = str[i];
}

void Printer::ShowString()
{
	cout << mText << endl;
}
