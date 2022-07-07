// 포인터를 사용한 value swapping

#include <iostream>
using namespace std;

void Swap(int* a, int* b);
void Swap(char* a, char* b);
void Swap(double* a, double* b);

int main()
{
    int num1 = 20, num2 = 30;
    Swap(&num1, &num2);
    cout << num1 << " " << num2 << endl;

    char ch1 = 'A', ch2 = 'B';
    Swap(&ch1, &ch2);
    cout << ch1 << " " << ch2 << endl;

    double dbl1 = 1.111, dbl2 = 5.555;
    Swap(&dbl1, &dbl2);
    cout << dbl1 << " " << dbl2 << endl;
}

void Swap(int* a, int* b)
{
    int val = *a;
    *a = *b;
    *b = val;
}

void Swap(char* a, char* b)
{
    char val = *a;
    *a = *b;
    *b = val;
}

void Swap(double* a, double* b)
{
    double val = *a;
    *a = *b;
    *b = val;
}

