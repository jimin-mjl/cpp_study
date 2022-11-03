#include <iostream>
#include "String.h"

using namespace std;

// 생성자, 복사 생성자, 소멸자, 대입연산자
// +, +=, == 연산자
// <<, >> 연산자

int main()
{
    String str;
    cin >> str;
       
    str += String(" to myself");
    String str2 = String(str) + String(" 2");
    cout << str << endl;
    cout << str2 << endl;
}
