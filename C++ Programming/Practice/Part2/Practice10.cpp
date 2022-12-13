#include <iostream>
#include <string>
#include <vector>

// status: 200

using namespace std;


class NumDivisor {
	int num;
public:
	NumDivisor(int a);
	int getDivisorSum();
	friend ostream& operator<<(ostream& os, NumDivisor& nd);

};


/* class NumDivisor 구현 */
NumDivisor::NumDivisor(int a) {
	num = a;
}


int NumDivisor::getDivisorSum() {
	int sum = 0;
	for (int i = 1; i <= num; i++) {
		if (num % i == 0) {
			sum += i;
		}
	}
	return sum;
}

ostream& operator<<(ostream& os, NumDivisor& nd) {
	cout << nd.num << "의 약수의 합: " << nd.getDivisorSum() << endl;

	return os;
}



int main() {

	NumDivisor nd(12);
	cout << nd;

	return 0;

}