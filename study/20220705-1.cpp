#include <iostream>
using namespace std;

int main()
{
    #pragma region 별만들기 게임 
    // 사용자에게서 정수 N을 받아서 N*N 모양의 별을 만들어라

    int input;
    cin >> input;

    for (int i = 0; i < input; i++) {
        for (int k = 0; k < input; k++) {
            cout << "*";
        }
        cout << endl;
    }

    //cout << "booya! \n";
    #pragma endregion

    #pragma region 별만들기 게임2 
    // 사용자에게서 정수 N을 받아서 별이 N줄까지 하나부터 순차적으로 증가하도록 만들어라

    int input2;
    cin >> input2;

    for (int i = 0; i < input2; i++) {
        for (int k = 0; k < i+1; k++) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "Booya! \n";
    #pragma endregion

    #pragma region 별만들기 게임3
    // 사용자에게서 정수 N을 받아서 별이 N줄까지 N개부터 순차적으로 줄어들도록 만들어라

    int input3;
    cin >> input3;

    for (int i = 0; i < input3; i++) {
        for (int k = input3; k > i; k--) {
            cout << "*";
        }
        cout << endl;
    }

    cout << "Booya! \n";
    #pragma endregion

    #pragma region 구구단
    // 2단부터 9단까지의 구구단을 출력하시오
    cout << "구구단을 출력합니다... \n";
    cout << endl;

    for (int i = 2; i < 10; i++) {
        for (int k = 2; k < 10; k++) {
            cout << i << " x " << k << " = " << i * k << endl;
        }
    }

    cout << endl;
    cout << "구구단을 출력이 완료되었습니다! \n";
    #pragma endregion

    return 0;
}
