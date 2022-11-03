#pragma once
#include <vector>

using namespace std;

class String
{
public:
	String() = default;
	String(const char* content);
	String(const String& other);
	String(std::vector<char> buffer);
	~String();

	// operators
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);
	bool operator==(const String& other);
	String operator+(const String& other);
	void operator+=(const String& other);
	void operator=(const String& other);

	size_t size() const { return mBuffer.size(); }
	std::vector<char> buffer() const { return mBuffer; }

private:
	std::vector<char> mBuffer;
};

