#include <iostream>

using namespace std;

// �����ڿ� �ΰ��� ���� �Է¹޾� ���� ����� ����Ͻÿ�.
// ��, �Է��� �޴� ������ ������, ��1, ��2 �̴�.

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