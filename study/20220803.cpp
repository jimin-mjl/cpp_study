#include <iostream>
#include <vector>

std::vector<int> v;

bool HasNumber(int num);
std::vector<int>::iterator FindElementDivisibleByNumber(int num);
int CountOddNumbers();
void IncreaseElementsByNumber(int num);

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
	bool has50 = HasNumber(number);
	std::cout << has50 << std::endl;

	// 2. number�� ������ �������� ù ��° ���ڸ� ��ȯ�ϴ� ��� 
	std::vector<int>::iterator findIt = FindElementDivisibleByNumber(11);
	std::cout << findIt._Ptr << std::endl;

	// 3. Ȧ���� ������ ������ ��ȯ�ϴ� ��� 
	std::cout << CountOddNumbers() << std::endl;

	// 4. �迭�� ��� ���ڵ鿡 �־��� ���� ���ϴ� ���
	std::cout << v[0] << std::endl;
	IncreaseElementsByNumber(3);
	std::cout << v[0] << std::endl;
}

bool HasNumber(int num)
{
	bool found = false;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == num)
		{
			found = true;
			break;
		}
	}

	return found;
}

std::vector<int>::iterator FindElementDivisibleByNumber(int num)
{
	std::vector<int>::iterator it;
	it._Ptr = nullptr;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % num == 0)
		{
			it = v.begin() + i;
			break;
		}
	}

	return it;
}

int CountOddNumbers()
{
	int count = 0;

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] % 2 == 1)
		{
			count++;
		}
	}

	return count;
}

void IncreaseElementsByNumber(int num)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] += num;
	}
}
