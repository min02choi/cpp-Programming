#include <iostream>

using namespace std;

class Negative { };

class Sample {

private:		// default. ���� �����־ ��
	int m;

public:
	int n;
	Sample() {		// constructor. class�̸��� ���ƾ� ��
		m = 0;
		n = 0;
		cout << "Sample() is called." << endl;
	}
	Sample(int x) {
		m = x;
		cout << "Sample(int i) is called." << endl;
	}
	

	void setM(int x) {
		if (x < 0) throw Negative();
		m = x;
	}
	int getM() {
		return m;
	}
};

int main() {
	Sample x, y, z(100);

	x.setM(2);		// class���ο� �ִ� �Լ��� ���� ��ȸ������ m����
	y.setM(20);

	cout << "x.m = " << x.getM() << endl;
	cout << "y.m = " << y.getM() << endl;
	cout << "z.m = " << z.getM() << endl;

	return 0;

}

/*
	constructor -> class�� ȣ���� �� �ڵ������� ȣ���
	class�� ȣ�� �� �� default constructorȣ��, ���� ���ص� ��
	default constructor�� ���ٸ� �����Ϸ��� �ڵ����� �������
	������ default constructor�� ���� ����ڰ� ������ �͸� ������ٸ� �Ű������� ���� constructor�� ����Ϸ��� default constructor�� ���� �����������
	������:	constructor�� �Ķ������ ������ type�� �޸��ϸ� �ߺ��� �̸����� �������� constructor�� ����� �� ����
*/