#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> v;

class IsDividedBy11
{
public:
	bool operator()(const int& num)
	{
		return num % 11 == 0;
	}
};

class IsOddNumber
{
public:
	bool operator()(const int& num)
	{
		return num % 2 != 0;
	}
};

class IncreaseBy3
{
public:
	void operator()(int& num)
	{
		num += 3;
	}
};

class IsEvenNumber
{
public:
	bool operator()(const int& num)
	{
		return num % 2 == 0;
	}
};

int main()
{
	srand((unsigned int)time(nullptr));
	for (int i = 0; i < 100; i++)
	{
		int val = rand() % 100;
		v.push_back(val);
	}

	// 1. number�� �迭�� �ִ��� üũ�ϴ� ��� 
	int number = 5;
	std::vector<int>::iterator findIt = std::find(v.begin(), v.end(), static_cast<const int>(number));
	std::cout << *findIt << std::endl;

	// 2. number�� ������ �������� ù ��° ���ڸ� ��ȯ�ϴ� ��� 
	std::vector<int>::iterator findIt2 = std::find_if(v.begin(), v.end(), IsDividedBy11());
	std::cout << *findIt2 << std::endl;

	// 3. Ȧ���� ������ ������ ��ȯ�ϴ� ��� 
	unsigned int count = std::count_if(v.begin(), v.end(), IsOddNumber());
	std::cout << count << std::endl;

	// 4. �迭�� ��� ���ڵ鿡 �־��� ���� ���ϴ� ���
	std::cout << v[0] << std::endl;
	std::for_each(v.begin(), v.end(), IncreaseBy3());
	std::cout << v[0] << std::endl;

	// 5. �迭���� ¦���� �����ϴ� ��� 
	std::vector<int> v2;
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(2);
	v2.push_back(6);

	std::vector<int>::iterator it = std::remove_if(v2.begin(), v2.end(), IsEvenNumber());
	v2.erase(it, v2.end());
}
