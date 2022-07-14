#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	// Q1
	char greeting[30] = "Hello World";
	cout << strlen(greeting) << endl;

	char greetingCopy[30];
	strcpy_s(greetingCopy, greeting);
	cout << greetingCopy << endl;

	strcat_s(greeting, " from here");
	cout << greeting << endl;

	int cmpResult = strcmp(greeting, greetingCopy);
	cout << cmpResult << endl;  // 0 : same / 1 : not same
}
