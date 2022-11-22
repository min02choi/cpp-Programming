#include <iostream>
#include <string>

using namespace std;

class PhoneNumber {
private:
	string number;
public:
	PhoneNumber(string num);
	string masking(int k) const;


};

PhoneNumber::PhoneNumber(string num) {
	number = num;
}

string PhoneNumber::masking(int k) const {
	for (int i = 0; i < number.length(); i++) {

	}
	// 리턴해주기
}

ostream& operator << (ostream& os, const PhoneNumber& p) {
	string masked = p.masking(7);
	os << masked;
	return os;
}

int main() {
	PhoneNumber pn("01022223333");
	cout << pn << endl;
}