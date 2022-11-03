#include <iostream>
#include "String.h"

String::String(const char* content)
{
	while (*content != '\0')
	{
		mBuffer.push_back(*content);
		++content;
	}
}

String::String(const String& other)
{
	mBuffer = other.buffer();
}

String::String(std::vector<char> buffer)
{
	mBuffer = buffer;
}

String::~String()
{
	mBuffer.clear();
}

bool String::operator==(const String& other)
{
	if (mBuffer == other.buffer())
		return true;
	return false;
}

String String::operator+(const String& other)
{
	for (char letter : other.buffer())
		mBuffer.push_back(letter);

	return String(mBuffer);
}

void String::operator+=(const String& other)
{
	for (char letter : other.buffer())
		mBuffer.push_back(letter);
}

void String::operator=(const String& other)
{
	mBuffer = other.buffer();
}

ostream& operator<<(ostream& os, const String& str)
{
	for (char letter : str.buffer())
		os << letter;
	return os;
}

istream& operator>>(istream& is, String& str)
{
	char input[100];
	is >> input;
	str = String(input);
	return is;
}
