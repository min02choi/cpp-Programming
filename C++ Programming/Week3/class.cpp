#include <iostream>

using namespace std;


void myfunc() {
	cout << "my" << endl;
}

void myfunc(int a) {	// ������ : �̸��� ���Ƶ� �Ű������� �ٸ��� �ߺ��� ���Ƿ� �������� ����
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