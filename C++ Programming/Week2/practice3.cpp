#include <iostream>

using namespace std;

// 수를 입력받아 짝수/홀수 판별을 하시오.

int main() {

	int num;
	string cat;
	cout << "Please enter a number: ";
	cin >> num;

	if (num % 2 == 0) {
		cat = "even";
		cout << "The value " << num << " is an even number." << endl;
	}
	else {
		cat = "odd";
		cout << "The value " << num << " is an odd number." << endl;
	}

	cout << "The value " << num << " is an " << cat << " number." << endl;	// 이 방법도 있음

	return 0;
}

// 이거 결석되면 휴학하면 그만이야~^^^