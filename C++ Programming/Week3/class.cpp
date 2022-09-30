#include <iostream>

using namespace std;


void myfunc() {
	cout << "my" << endl;
}

void myfunc(int a) {	// 다형성 : 이름이 같아도 매개변수가 다르면 중복된 정의로 인지하지 않음
	cout << a << endl;
}

void myfunc(float f) {
	cout << "my" << endl;
}

int main() {

	myfunc();
	myfunc(1.0f);
	int arr[2] = { 1, 3 };

}