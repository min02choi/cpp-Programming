#include <iostream>

using namespace std;

// ���� �Է¹޾� ¦��/Ȧ�� �Ǻ��� �Ͻÿ�.

int main() {

	int num;
	string cat;
	cout << "Please enter a number: ";
	cin >> num;

	if (num % 2 == 0) {
		cat = "even";
		cout << "The value " << num << " is an even number." << endl;
	}
	else {
		cat = "odd";
		cout << "The value " << num << " is an odd number." << endl;
	}

	cout << "The value " << num << " is an " << cat << " number." << endl;	// �� ����� ����

	return 0;
}

// �̰� �Ἦ�Ǹ� �����ϸ� �׸��̾�~^^^