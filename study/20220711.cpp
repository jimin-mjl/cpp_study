#include <iostream>
using namespace std;

void Swap(int& a, int& b);
void Sort(int arr[], int length);
void ChooseLotto(int arr[], int length);
bool IsDuplicated(int num, int arr[], int length);

int main()
{
    // 1) Implement swapping with reference
    int a = 3;
    int b = 5;
    Swap(a, b);
    cout << a << " " << b << endl;

    // 2) Implement sort (ascending) 
    int arr[] = { 1, 34, 52, 2, 10, 55 };
    // How to calculate the size of an array : sizeof(arr) / sizeof(arrType)
    int arrLength = sizeof(arr) / sizeof(int);
    Sort(arr, arrLength);
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    // 3) Implement a Lotto numbers generator 
    // Randomly choose six numbers between 1 ~ 45 (duplicated numbers not allowed) 
    const int TOTAL = 6;
    int lotto[TOTAL];
    ChooseLotto(lotto, TOTAL);
    for (int i = 0; i < TOTAL; i++)
    {
        cout << lotto[i] << " ";
    }
}

void Swap(int& a, int& b)
{
    int backup = a;
    a = b;
    b = backup;
}

void Sort(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                Swap(arr[i], arr[j]);
            }
        }
    }
}

void ChooseLotto(int arr[], int length)
{
    srand(time(0));  // set Seed
    const int MAX_NUM = 45;

    int i = 0;
    while (i < length)
    {
        int number = rand() % MAX_NUM + 1;

        if (!IsDuplicated(number, arr, i))
        {
            arr[i] = number;
            i++;
        }
    }

    Sort(arr, length);
}

bool IsDuplicated(int num, int arr[], int length)
{
    for (int i = 0; i < length; i++) {
        if (num == arr[i])
        {
            return true;
        }
    }
    return false;
}
