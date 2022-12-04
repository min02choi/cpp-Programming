#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Practice8 {
	int n;
	bool isPrime(int num);
public:
	Practice8(int n);
	int solution();
};

/*  class Practice8 ±¸Çö */
bool Practice8::isPrime(int num) {
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

Practice8::Practice8(int n) {
	this->n = n;
}

int Practice8::solution() {
	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) {
			count++;
		}
	}
	return count;
}


int main() {
	
	Practice8 p8(5);
	cout << p8.solution() << endl;

	return 0;

}