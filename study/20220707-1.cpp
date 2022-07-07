// 디폴트 매개변수 

#include <iostream>
using namespace std;

int BoxVolume(int length, int width, int height);
int BoxVolume(int length, int width);
int BoxVolume(int length);

int main() {

	cout << "[3, 3, 3] : " << BoxVolume(3, 3, 3) << endl;
	cout << "[3, 3, D] : " << BoxVolume(3, 3) << endl;
	cout << "[3, D, D] : " << BoxVolume(3) << endl;

}

int BoxVolume(int length, int width, int height) {
	return length * width * height;
}

int BoxVolume(int length, int width) {
	return length * width * 1;
}

int BoxVolume(int length) {
	return length * 1 * 1;
}
