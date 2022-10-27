#include <iostream>

using namespace std;

class Negative { };

class Sample {

	private:		// default. ���� �����־ ��
		int m;

	public:

		int n;	// �ܺο��� �ٲ㵵 ������ ����� ����

		void setM(int x) {
			if (x < 0) throw Negative();	// ����Ǵ� ���
			m = x;
		}
		int getM() {
			return m;
		}
};

int main() {
	Sample x, y;
	x.n = 1;
	y.n = 10;
	// x.m = 1;		// Error: m�� private�̹Ƿ� ���� �Ұ�
	// y.m = 10;	// Error: m�� private�̹Ƿ� ���� �Ұ�
	x.setM(2);		// class���ο� �ִ� �Լ��� ���� ��ȸ������ m����
	y.setM(20);

	cout << "x.n = " << x.n << endl;
	cout << "y.n = " << y.n << endl;

	cout << "x.m = " << x.getM() << endl;
	cout << "y.m = " << y.getM() << endl;

}

/*
	n, m�� ���� ��� �� m����� �� ��ȣ��.
	m����� ����ϴ� ��� �Լ��� ���ؼ� ������ ���濡 ���� �� �� �� ������ �� �ִ� ��ȸ�� ��.
	�� �ڵ��� ���, m�� ������ �Ǹ� �ȵǴ� ���(����), �Լ� ������ �ѹ� ����͸� ����.

	ũ��? member������ ���� ũ�Ⱑ ������
*/