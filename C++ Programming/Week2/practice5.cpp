#include <iostream>

using namespace std;

// 연산자와 두개의 수를 입력받아 연산 결과를 출력하시오.
// 단, 입력을 받는 순서는 연산자, 값1, 값2 이다.

int main() {
	
	char op;
	double val1, val2, result;

	cin >> op >> val1 >> val2;
	cin >> val1;

	switch (op) {
		case '+':
			result = val1 + val2;
			break;
		case '-':
			result = val1 - val2;
			break;
		case '*':
			result = val1 * val2;
			break;
		case '/':
			result = val1 / val2;
			break;
		default:
			break;
	}
	cout << val1 << " " << op << " " << val2 << " = " << result << endl;
	
}