#include <iostream>
#include <string>
#include <vector>

// status: 200


using namespace std;

class Numbers {
	int n;
	int m;
	int getMinNum();
public:
	Numbers(int a, int b);
	int getGCD();
	int getLCM();
	friend ostream& operator<<(ostream& os, Numbers& nb);
};

/* class Number 구현 */
Numbers::Numbers(int a, int b) {
	n = a;
	m = b;
}

int Numbers::getMinNum() {
	int temp = n;
	if (n > m) {
		temp = m;
	}
	return temp;
}

int Numbers::getGCD() {
	for (int i = getMinNum(); ; i--) {
		if ((n % i == 0) && (m % i == 0)) {
			return i;
		}
	}
	return 1;
}

int Numbers::getLCM() {
	return n * m / getGCD();
}

ostream& operator<<(ostream& os, Numbers& nb) {
	cout << "최대공약수: " << nb.getGCD() << endl;
	cout << "최소공배수: " << nb.getLCM() << endl;
	return os;
}

int main() {

	Numbers nb(2, 5);
	cout << nb;

	return 0;

}