#include <iostream>

using namespace std;

class myerror { };

int division(int i, int j) {
	
	/*
	// c������ �ڵ� - �Ϲ����� �ڵ�� ���� ���̰� ����
	if (j == 0) {
		return -9999;
	}
	else {
		return i / j;
	}
	*/

	// c++������ �ڵ� - ������ Ȯ���ϰ� ǥ��(try, catch)
	if (j == 0) {
		throw myerror();	// ���� ��Ȳ �߻�
	}
	else {
		return i / j;
	}
}

int main() {
	int i, j;
	cin >> i >> j;

	try {
		int ans = division(i, j);
		cout << ans;
	}

	// catch - ���� ��Ȳ�� ���� ó��
	catch (myerror e) {		// ���� �ڵ�� ���������� ��Ȳ�� ���� ����
		cout << "myerror";
	}

	return 0;
}