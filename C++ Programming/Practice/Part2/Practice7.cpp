#include <iostream>
#include <string>

// status: 200
// ���ص�: 10
// replace(�����ε���, ��-1�ε���, ��ü����)��� �Լ��� �ִ�. �ϴ� �˾Ƴ�����. ����� ����


using namespace std;

class PhoneNumber {
	string number;
public:
	PhoneNumber(string n);
	string numberMask();
};

/* class PhoneNumber ���� */
PhoneNumber::PhoneNumber(string n) {
	number = n;
}

string PhoneNumber::numberMask() {
	string newnum = "";
	for (int i = number.length(); i >= number.length() - 4; i--) {
		newnum = number[i] + newnum;
	}
	for (int i = number.length() - 5; i >= 0; i--) {
		newnum = '*' + newnum;
	}
	return newnum;
}

int main() {
	string s = "01012348277778";
	PhoneNumber pn(s);

	cout << pn.numberMask() << endl;

}