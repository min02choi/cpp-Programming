#include <iostream>

using namespace std;

// ���ڸ� ������ �Է¹޾� �ش� ���� ����� ����Ͻÿ�.
// ��, �Է¹޴� ���� ������ 0~4 �̴�.

int main() {

	string numbers[5] = { "zero", "one", "two", "three", "four"};

	int flag = 0;
	string num;
	cin >> num;

	for (int i = 0; i < 5; i++) {
		if (num == numbers[i]) {	// string�� ���� == ���� ����
			flag = 1;
			cout << i;
			break;
		}
	}
	if (flag == 0) {	// ���� ���� ���
		cout << "not a value!" << endl;
	}	

	// switch���� �Ű������� user definded type�� ���� ����. char, int�� ���� �͸� ����


	return 0;
}