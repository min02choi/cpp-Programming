#include <iostream>
#include <string>

// status: 200
// 이해도: 10
// replace(시작인덱스, 끝-1인덱스, 대체글자)라는 함수도 있다. 일단 알아놓으셈. 써먹을 수도


using namespace std;

class PhoneNumber {
	string number;
public:
	PhoneNumber(string n);
	string numberMask();
};

/* class PhoneNumber 구현 */
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