// static members in classes

#include <iostream>

/*
	class���� static ������ ���ؼ�
	static ��� �Լ�
*/

using namespace std;

class CDummy {
	public:
		static int n;		// Ŭ������ ���� ��� ������ ����
		int m;

		CDummy() {
			// n = 0;		// ���⼭ �ʱ�ȭ�� �ϸ� ��ü�� ������ ������ �ʱ�ȭ��
			n++;
		};
		~CDummy() {	
			n--;
		};
		static int getN() {			// static�� this��� ������ ����
			// return n + m;		// �Լ��� static�� (������) m���� Ư���� �� ����. m�� object�� ������
			return n;
		}
		int getM() {
			return n + m;			// ��������
		}
};

// static ���� �ʱ�ȭ�� �̷� ������ ��
int CDummy::n = 0;			// �ٱ����� ������ �ʱ�ȭ. �� �ѹ� ����

int main() {

	// CDummy::getM();
	// getN()

	CDummy a;				// ����, 1�� ����, �� 6��
	CDummy b[5];			// ����, 5�� ����, �� 6��
	CDummy* c = new CDummy;	// ��, 1�� ����, �� 7��

	// �� �������� n�� 7�� ȣ��Ǿ����Ƿ� n = 7
	cout << a.n << endl;

	delete c;	// �ϳ��� �����

	cout << CDummy::n << endl;		// ��� static������°��� ����� (a.n�� ����)

	// ����: ũ�� ����
	// �Ϲ������� ��� �Լ��� ����X object�� ���ϴ°� �ƴ϶� class�� ���ϴ� ���̹Ƿ�.
	// ���� static�� ������ ���� ������ ���ؼ��� sizeof�� ���� ����.
	// ���� �ٸ� static�� �ƴ� ������ ������ �ش� object�� ũ��� static�� �ƴ� ������ ũ��� ���.
	// static������ ���� ���� ũ�⸦ "1"�̶�� ����
	cout << sizeof(a) << endl;
	
	return 0;
}