#include <iostream>
#include <string>
#include <vector>


using namespace std;

/* class MyString */
class MyString {
	string str;
	bool isCorrectLen();
	bool isAllNum();
public:
	MyString(string str);
	bool solution();
	friend ostream& operator<<(ostream& os, MyString ms);
};

/* class MyString ±¸Çö */
MyString::MyString(string str) {
	this->str = str;
}

bool MyString::solution() {
	if (isCorrectLen() && isAllNum()) {
		return true;
	}
	return false;
}

bool MyString::isCorrectLen() {
	if (str.length() == 4 || str.length() == 6) {
		return true;
	}
	return false;
}

bool MyString::isAllNum() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, MyString ms) {
	os << ms.str << " --> " << ms.solution() << endl;

	return os;
}

int main() {

	MyString ms("a1234");

	cout << ms.solution() << endl;
	cout << ms << endl;

	return 0;

}