#include <iostream>
#include <string>
#include <vector>

/*
	<����>
	- Practice5::Practice5(const char* a) : string(a) �κ�
	- MyString�� �̿��ϱ� ���ؼ�..?
	- � �� *�� �޴°���?
*/

using namespace std;


class MyString {
protected:
	char* pstr;
	void initPstr();
public:
	MyString();
	~MyString();
	void setString(const char* t);
	int length();
	char* getPstr();
	friend ostream& operator<<(ostream& os, const MyString& mys);
};

class Practice5 : public MyString, string {
public:
	Practice5(const char* a);
	bool solution();
};


/* class MyString ���� */
// ������
MyString::MyString() {
	pstr = NULL;
	initPstr();
}

// ��ü�� ���ִ� �Ҹ���
MyString::~MyString() {
	if (pstr != NULL) {
		delete[] pstr;
	}
}

// ��ü ����(ũ�� 10)
void MyString::initPstr() {
	pstr = new char[10];
}

// ������ ��ü�� �� ����
void MyString::setString(const char* t) {
	for (int i = 0; i < 10; i++) {
		pstr[i] = t[i];
		if (t[i] == '\0') {
			break;
		}
	}
}

int MyString::length() {
	int i;
	for (i = 0; i < 10; i++) {
		if (pstr[i] == '\0') {
			break;
		}
	}
	return i;
}

char* MyString::getPstr() {
	return pstr;
}

ostream& operator<<(ostream& os, const MyString& mys) {
	os << mys;		// � ���·� ����� �Ǵ��� Ȯ��
	return os;
}

/* class Practice5 ���� */
Practice5::Practice5(const char* a) : string(a) {	// ����
	;
}

bool Practice5::solution() {
	int len = MyString::length();		// ���� ����� ���� ���� string�� ���ؼ�..?
	if (len == 4 || len == 6) {
		for (int i = 0; i < 10 && pstr[i] != '\0'; i++) {
			if (pstr[i] < '0' || pstr[i] > '9') {
				return false;
			}
		}
	}
	else {
		return false;
	}
	return true;
}



int main() {

	MyString my;			// new�� ��ü..? �����ϴ� ��
	my.setString("test");	// ������ ��ü?�� �Է�

	Practice5 p5("123456");

	cout << my.length() << ":" << my.getPstr() << endl;

	delete[] my.getPstr();

	return 0;
}