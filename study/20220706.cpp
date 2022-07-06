#include <iostream>
using namespace std;

void AddNumbers();
void PrintNameAndPhone();
void PrintMultiplyTable();
void CalcSalary();

int main()
{
    AddNumbers();
    PrintNameAndPhone();
    PrintMultiplyTable();
    CalcSalary();
}

void AddNumbers() {
    // 사용자로부터 5개의 정수를 입력 받아서 그 합을 출력하는 프로그램을 작성해보자.

    int num1;
    int num2;
    int num3;
    int num4;
    int num5;

    cout << "다섯 개의 숫자를 입력해주세요" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int result = num1 + num2 + num3 + num4 + num5;

    cout << "총 합: " << result << endl;
}

void PrintNameAndPhone() {
    // 사용자로부터 이름과 전화번호를 문자열의 형태로 입력받아서, 입력받은 데이터를 그대로 출력하는 프로그램을 만들어보자. 
    char name[100];
    char phone[30];

    cout << "이름을 입력하세요: " << endl;
    cin >> name;
    cout << "전화번호를 입력하세요: " << endl;
    cin >> phone;
    cout << "이름: " << name << " 전화번호: " << phone << endl;
}

void PrintMultiplyTable() {
    // 숫자를 하나 입력 받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 만들어보자
    int num;
    cin >> num;

    for (int i = 1; i < 10; i++) {
        cout << num << "X" << i << "=" << num * i << endl;
    }
}

void CalcSalary() {
    // 물품 판매 금액을 입력받아 급여를 계산하는 프로그램을 작성해보자. 

    const int BASE_SALARY = 50;  // 기본급 50만 원
    const float INCENTIVE_RATE = 0.12f;  // 물품 판매액에 따른 인센티브 비율 12%

    while (true) {
        int revenue;  // 판매액 
        cin >> revenue;

        if (revenue == -1) {
            cout << "종료합니다" << endl;
            break;
        }

        int totalSalary = BASE_SALARY + revenue * INCENTIVE_RATE;
        cout << "판매액: " << revenue << endl;
        cout << "총 급여: " << totalSalary << "만 원" << endl;
    }

}
