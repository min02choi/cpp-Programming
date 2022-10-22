#include <iostream>

using namespace std;

class myerror { };

int division(int i, int j) {
	
	/*
	// c언어스러운 코딩 - 일반적인 코드와 별반 차이가 없음
	if (j == 0) {
		return -9999;
	}
	else {
		return i / j;
	}
	*/

	// c++스러운 코딩 - 에러는 확실하게 표현(try, catch)
	if (j == 0) {
		throw myerror();	// 문제 상황 발생
	}
	else {
		return i / j;
	}
}

int main() {
	int i, j;
	cin >> i >> j;

	try {
		int ans = division(i, j);
		cout << ans;
	}

	// catch - 문제 상황에 대한 처리
	catch (myerror e) {		// 내부 코드는 비정상적인 상황일 때만 실행
		cout << "myerror";
	}

	return 0;
}