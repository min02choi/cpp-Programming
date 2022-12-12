#include <iostream>
#include <string>
#include <vector>

/*
	<질문>
	- Practice5::Practice5(const char* a) : string(a) 부분
	- MyString을 이용하기 위해선..?
	- 어떨 때 *로 받는거지?
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


/* class MyString 구현 */
// 생성자
MyString::MyString() {
	pstr = NULL;
	initPstr();
}

// 객체를 없애는 소멸자
MyString::~MyString() {
	if (pstr != NULL) {
		delete[] pstr;
	}
}

// 객체 생성(크기 10)
void MyString::initPstr() {
	pstr = new char[10];
}

// 생성된 객체에 값 기입
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
	os << mys;		// 어떤 형태로 출력이 되는지 확인
	return os;
}

/* class Practice5 구현 */
Practice5::Practice5(const char* a) : string(a) {	// 질문
	;
}

bool Practice5::solution() {
	int len = MyString::length();		// 냅다 갈기면 누가 나옴 string에 대해서..?
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

	MyString my;			// new로 객체..? 생성하는 것
	my.setString("test");	// 생성된 객체?에 입력

	Practice5 p5("123456");

	cout << my.length() << ":" << my.getPstr() << endl;

	delete[] my.getPstr();

	return 0;
}