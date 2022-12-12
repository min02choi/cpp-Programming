#include <iostream>
#include <string>
#include <vector>

// ������ 3���������� 3������ �ƴ� n���� �󿡼� ��������

using namespace std;

class Arithmetic {
	int n;
	int changeNum();
	string reverseNum(int newnum);
	int toDecimal(string rev);
	vector<int> changeNumRev();
	int toDecimal(vector<int> rev);
	int returnNum();
public:
	Arithmetic(int num);
	int solution();
	friend ostream& operator<<(ostream& os, Arithmetic at);
};


/* class Arithmatic ���� */
Arithmetic::Arithmetic(int num) {
	n = num;
}

int Arithmetic::solution() {
	int newnum;
	// newnum = changeNum();	// n�������� ����(int)
	// string rev = reverseNum(newnum);	// ���� ������(string)
	// int answer = toDecimal(rev);

	vector<int> numList = changeNumRev();
	int answer = toDecimal(numList);
	

	return answer;
}

vector<int> Arithmetic::changeNumRev() {
	int s = returnNum();	// ����
	int quo = n;	// '����' ���� �ɰ�
	int rem = 0;	// ������
	vector<int> vec;

	while (true) {
		if (quo < s) {
			vec.push_back(quo);
			break;
		}
		rem = quo % s;
		vec.push_back(rem);
		quo /= s;
	}

	// vector�� �׳� �Ѱܵ� �ɰŰ�����...?

	return vec;

}

int Arithmetic::toDecimal(vector<int> rev) {
	int answer = 0;
	int s = returnNum();
	int mul = 1;

	for (int i = rev.size() - 1; i >= 0; i--) {
		answer += rev[i] * mul;
		mul *= s;
	}
	return answer;
}

int Arithmetic::returnNum() {
	return 3;
}

ostream& operator<<(ostream& os, Arithmetic at) {
	os << "10����: " << at.n << endl;
	os << at.returnNum() << "�������� ���� �� ������ 10�������� ǥ��: " << at.solution() << endl;

	return os;
}

int main() {

	Arithmetic arit(125);

	cout << arit << endl;

	return 0;

}
