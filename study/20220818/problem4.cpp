#include <iostream>
using namespace std;

class Book
{
public:
	Book(const char* title, const char* isbn, const int price)
		: mPrice(price)
	{
		size_t titleSize = strlen(title) + 1;
		size_t isbnSize = strlen(isbn) + 1;

		mTitle = new char[titleSize];
		strcpy_s(mTitle, titleSize, title);

		mIsbn = new char[isbnSize];
		strcpy_s(mIsbn, isbnSize, isbn);
	}
	virtual ~Book()
	{
		if (mTitle)
		{
			delete mTitle;
		}

		if (mIsbn)
		{
			delete mIsbn;
		}
	}
	void PrintBookInfo()
	{
		cout << "Title: " << mTitle << endl;
		cout << "ISBN: " << mIsbn << endl;
		cout << "Price: " << mPrice << endl;
	}

private:
	char* mTitle;
	char* mIsbn;
	int mPrice;
};

class EBook : public Book
{
public:
	EBook(const char* title, const char* isbn, const int price, const char* key)
		: Book(title, isbn, price)
	{
		size_t size = strlen(key) + 1;
		MsecurityKey = new char[size];
		strcpy_s(MsecurityKey, size, key);
	}
	virtual ~EBook()
	{
		if (MsecurityKey)
		{
			delete MsecurityKey;
		}
	}

private:
	char* MsecurityKey;
};

int main()
{
	Book book("Good C++", "555-12345-22-0", 20000);
	book.PrintBookInfo();

	EBook ebook("Good C++ EBook", "555-12345-22-1", 16000, "fdicnsx");
	ebook.PrintBookInfo();
}