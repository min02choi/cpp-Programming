#include <iostream>
#include <string>

using namespace std;

class PhoneNumber {
private:
	string number;
public:
	PhoneNumber

};

PhoneNumber::PhoneNumer(string num) {
	number = num;
}

string PhoneNumber::masking(int k) const {
	for (int i = 0; i < number.length(); i++) {

	}
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