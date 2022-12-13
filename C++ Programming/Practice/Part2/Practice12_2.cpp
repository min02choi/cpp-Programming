#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BitCompare {
	long long n;
	int difference(int num);
	int limit();
public:
	BitCompare(long long n);
	long long solution();
};

/* class BitCompare ±¸Çö */
BitCompare::BitCompare(long long n) {
	this->n = n;
}

int BitCompare::difference(int num) {
	long long mask = 1;
	int cnt = 0;
	int len = sizeof(num) * 8;
	for (int i = 0; i < len; i++) {
		if ((mask & n) != (mask & num)) {
			cnt++;
		}
		mask = mask << 1;	// Çõ½Å!
	}
	return cnt;
}

int BitCompare::limit() {
	return 2;
}

long long BitCompare::solution() {
	int dif;
	int i;
	for (i = n + 1; ; i++) {
		dif = difference(i);
		if (dif <= limit()) {
			return i;
		}
	}
	return i;
}

int main() {

	BitCompare bt(7);
	cout << bt.solution() << endl;

	return 0;

}