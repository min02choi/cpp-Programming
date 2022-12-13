#include <iostream>
#include <string>
#include <vector>

// status: 200
// ���ص�: 9

/*
	- ����ũ ����ϴ� ��� �ٽ� �� ��!	
*/

/*
	12�� ������ ��¦ �����ؼ� �ϴ��� ���� �ϳ��� ������ ��Ʈ 2������ �ٸ� ���� ����
	�Է°� vector�ε� �ѹ� �غ� ��
	#class, #���
*/

/*
	[���� ���]
	solution���� �ٸ� �Լ����� �θ� -> solution�� public, �� ���� �Լ����� private
*/

/*
	����
	��Ʈ�����ڸ� �׳� 10�������� ���� �ݿ��� ��?
	�ϰ��غ���
	��
*/

using namespace std;

/////////////// Ŭ���� ���� ///////////////////////////

// ��Ʈ �ٸ� 2������ ���
class Practice12 {
protected:
	long long n;
	int difference(long long n, long long i);
	virtual int limit();
public:
	Practice12(long long a);
	long long solution();
};

// ��Ʈ �ٸ� 3������ ���
class Practice12_2 : public Practice12 {
	virtual int limit();	// virtual �θ𿡸� ���൵ ��
public:
	Practice12_2(long long a);
};

///////////// Ŭ���� ���� ///////////////////

/* class Practice12 ���� */
Practice12::Practice12(long long a) {
	this->n = a;
}

// �� ���� ������ �޾� ��Ʈ�� ���ϰ� �ٸ� �ڸ��� ������ ��ȯ
// ��Ʈ����ũ ���. �� �ٵ� ��¥ õ�鰡 �� ��
int Practice12::difference(long long n, long long i) {
	int count = 0;
	int len = sizeof(n) * 8;		// ����
	long long mask = 1;
	for (int j = 0; j < len; j++) {
		if ((n & mask) != (i & mask)) {
			count++;
		}
		mask = mask << 1;
	}
	return count;
}

int Practice12::limit() {
	return 2;
}

long long Practice12::solution() {
	int dif;
	int ans;
	for (int i = n + 1; ; i++) {
		dif = difference(n, i);
		if (dif >= 1 && dif <= limit()) {
			ans = i;
			// break;
			return ans;
		}
	}
	return ans;
}

/* class Practice12_2 ���� */
Practice12_2::Practice12_2(long long a) : Practice12(a){
	;
	// n = a;
	// Practice12(a);
	// ����: �ʱ�ȭ ��� �̻�?
}

int Practice12_2::limit() {
	return 3;
}



int main() {

	vector<long long> num;		// ���� ����
	num = { 2, 7 };

	Practice12 p12(7);
	cout << p12.solution() << endl;

	Practice12_2 p12_2(7);
	cout << p12_2.solution() << endl;

	return 0;
}

// Ŭ���� ���, ������ �����ε�, ���