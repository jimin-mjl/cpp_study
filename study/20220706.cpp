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
    // ����ڷκ��� 5���� ������ �Է� �޾Ƽ� �� ���� ����ϴ� ���α׷��� �ۼ��غ���.

    int num1;
    int num2;
    int num3;
    int num4;
    int num5;

    cout << "�ټ� ���� ���ڸ� �Է����ּ���" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5;

    int result = num1 + num2 + num3 + num4 + num5;

    cout << "�� ��: " << result << endl;
}

void PrintNameAndPhone() {
    // ����ڷκ��� �̸��� ��ȭ��ȣ�� ���ڿ��� ���·� �Է¹޾Ƽ�, �Է¹��� �����͸� �״�� ����ϴ� ���α׷��� ������. 
    char name[100];
    char phone[30];

    cout << "�̸��� �Է��ϼ���: " << endl;
    cin >> name;
    cout << "��ȭ��ȣ�� �Է��ϼ���: " << endl;
    cin >> phone;
    cout << "�̸�: " << name << " ��ȭ��ȣ: " << phone << endl;
}

void PrintMultiplyTable() {
    // ���ڸ� �ϳ� �Է� �޾Ƽ� �� ���ڿ� �ش��ϴ� �������� ����ϴ� ���α׷��� ������
    int num;
    cin >> num;

    for (int i = 1; i < 10; i++) {
        cout << num << "X" << i << "=" << num * i << endl;
    }
}

void CalcSalary() {
    // ��ǰ �Ǹ� �ݾ��� �Է¹޾� �޿��� ����ϴ� ���α׷��� �ۼ��غ���. 

    const int BASE_SALARY = 50;  // �⺻�� 50�� ��
    const float INCENTIVE_RATE = 0.12f;  // ��ǰ �Ǹž׿� ���� �μ�Ƽ�� ���� 12%

    while (true) {
        int revenue;  // �Ǹž� 
        cin >> revenue;

        if (revenue == -1) {
            cout << "�����մϴ�" << endl;
            break;
        }

        int totalSalary = BASE_SALARY + revenue * INCENTIVE_RATE;
        cout << "�Ǹž�: " << revenue << endl;
        cout << "�� �޿�: " << totalSalary << "�� ��" << endl;
    }

}
