#include <iostream>

using namespace std;

// 숫자를 정수로 입력받아 해당 수를 영어로 출력하시오.
// 단, 입력받는 수의 범위는 0~4 이다.

int main() {

	string numbers[5] = { "zero", "one", "two", "three", "four"};

	int flag = 0;
	string num;
	cin >> num;

	for (int i = 0; i < 5; i++) {
		if (num == numbers[i]) {	// string에 대해 == 연산 수행
			flag = 1;
			cout << i;
			break;
		}
	}
	if (flag == 0) {	// 값이 없는 경우
		cout << "not a value!" << endl;
	}	

	// switch문은 매개변수로 user definded type가 들어가지 못함. char, int와 같은 것만 가능


	return 0;
}