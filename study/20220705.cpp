#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

string ConvertString(int weapon) {
    switch (weapon)
    {
    case SCISSORS:
        return "����";
    case ROCK:
        return "����";
    case PAPER:
        return "��";
    default:
        return "�߸��� �Է°�";
    }
}

int main()
{
    srand(time(0));  // ���� �õ� ���� 

    int winCount = 0, totalCount = 0;

    while (true) {
        int input;
        cout << "����(1), ����(2), ��(3)  �� �ϳ��� �������ּ��� (���ڸ� �����մϴ�) :" << endl;
        cin >> input;

        if (input > 3) {
            int rate = (float)winCount / totalCount * 100;  // ���� ���� ������ ������ ��ȯ�ǹǷ� �� �� �ϳ��� �Ǽ��� ��ȯ�ؼ� ���

            cout << "�ùٸ� ���ڸ� �Է����� �ʾ� ������ ����˴ϴ�." << endl;
            cout << "�� �·�: " << rate << endl;
            break;
        }

        int computer = (rand() % 3) + 1;  // 1, 2, 3
        cout << "You: " << ConvertString(input) << " vs " << "Computer: " << ConvertString(computer) << endl;

        if (input == computer) {
            cout << "�����ϴ�." << endl;
        }
        else if ((computer / input == PAPER) || (input > computer)) {
            cout << "�̰���ϴ�!" << endl;
            winCount++;
        }
        else {
            cout << "�����ϴ�..." << endl;
        }

        totalCount++;
        cout << "������� " << totalCount << "��" << winCount << "��" << endl;
    }

    return 0;
}
