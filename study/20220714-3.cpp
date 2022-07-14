#include <iostream>
using namespace std;

int GetStrLen(const char* str);
char* CopyStr(char* dest, const char* src);
char* ConcatStr(char* dest, const char* src);
bool CompareStr(const char* str1, const char* str2);
void ReverseStr(char* str);

int main()
{
	// Implement strlen()
	const int BUF_SIZE = 100;
	char greeting[BUF_SIZE] = "Hello";
	int length = GetStrLen(greeting);
	cout << length << endl;

	// Implement strcpy()
	char greetingCopy[BUF_SIZE];
	CopyStr(greetingCopy, greeting);
	cout << strcmp(greeting, greetingCopy) << endl;

	// Implement strcat()
	ConcatStr(greeting, " World");
	cout << strcmp(greeting, "Hello World") << endl;

	//Implement strcmp()
	bool isSame = CompareStr("Hello", "Hello ");
	cout << isSame << endl;

	//Implement string reverse function
	char str[BUF_SIZE] = "Hello";
	ReverseStr(str);
	for (int i = 0; i < 5; i++)
	{
		cout << str[i];
	}
}

int GetStrLen(const char* str)
{
	int count = 0;
	while (str[count] != NULL)
	{
		count++;
	}

	return count;
}

char* CopyStr(char* dest, const char* src)
{
	int i = 0;
	while (src[i] != NULL)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';  // The end of the string should always be NULL

	return dest;
}

char* ConcatStr(char* dest, const char* src)
{
	int destLen = GetStrLen(dest);

	int i = 0;
	while (src[i] != NULL)
	{
		dest[destLen + i] = src[i];
		i++;
	}
	dest[destLen + i] = '\0';

	return dest;
}

bool CompareStr(const char* str1, const char* str2)
{
	bool isSame = true;
	int i = 0;

	while (str1[i] != NULL || str2[i] != NULL)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
		i++;
	}

	return true;
}

void ReverseStr(char* str)
{
	int len = GetStrLen(str);

	for (int i = 0; i < (len / 2); i++)
	{
		int temp = str[i];
		str[i] = str[len - (i + 1)];
		str[len - (i + 1)] = temp;
	}
}