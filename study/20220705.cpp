#include <iostream>
using namespace std;

const int SCISSORS = 1;
const int ROCK = 2;
const int PAPER = 3;

string ConvertString(int weapon) {
    switch (weapon)
    {
    case SCISSORS:
        return "가위";
    case ROCK:
        return "바위";
    case PAPER:
        return "보";
    default:
        return "잘못된 입력값";
    }
}

int main()
{
    srand(time(0));  // 난수 시드 생성 

    int winCount = 0, totalCount = 0;

    while (true) {
        int input;
        cout << "가위(1), 바위(2), 보(3)  중 하나를 제시해주세요 (숫자만 가능합니다) :" << endl;
        cin >> input;

        if (input > 3) {
            int rate = (float)winCount / totalCount * 100;  // 정수 간의 연산은 정수가 반환되므로 둘 중 하나를 실수로 변환해서 계산

            cout << "올바른 숫자를 입력하지 않아 게임이 종료됩니다." << endl;
            cout << "총 승률: " << rate << endl;
            break;
        }

        int computer = (rand() % 3) + 1;  // 1, 2, 3
        cout << "You: " << ConvertString(input) << " vs " << "Computer: " << ConvertString(computer) << endl;

        if (input == computer) {
            cout << "비겼습니다." << endl;
        }
        else if ((computer / input == PAPER) || (input > computer)) {
            cout << "이겼습니다!" << endl;
            winCount++;
        }
        else {
            cout << "졌습니다..." << endl;
        }

        totalCount++;
        cout << "현재까지 " << totalCount << "판" << winCount << "승" << endl;
    }

    return 0;
}
