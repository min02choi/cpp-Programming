#include <iostream>
#include <new>

using namespace std;

int main() {

	int i, n;
	int* p;
	cout << "How many numbers would you like to type? ";
	cin >> i;
	p = new (nothrow) int[i];

	if (p == 0) {	// 메모리 allocation이 실패한 경우
		cout << "Error: memory could not be allocated";
	}

	else {
		for (n = 0; n < i; n++) {
			cout << "Enter number: ";
			cin >> p[n];
		}
		cout << "You have entered: ";
		for (n = 0; n < i; n++) {
			cout << p[n] << ", ";
		}

		delete[] p;	
		// 꺽쇠가 반드시 필요함
		// 꺽쇠 안해줄 시 맨 앞의 요소만 삭제됨. 나머지 요소는 leak

	}
	return 0;
}
