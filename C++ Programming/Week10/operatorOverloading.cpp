#include <iostream>
#include "operatorOverloading.h"		// 사용자 정의 헤더파일

// ㅋㅋ 안돌아감

using namespace std;

// class Negative { };

Sample::Sample() {
	m = 0;
	cout << "Sample(int i) is called." << endl;
}

Sample::Sample(int x) : m{ x } {		// 이런 방법도 있다~ 근데 권장하지는 않음
	m = x;						// 걍 이게 직관적. 이거써라
	cout << "Sample(int i) is called." << endl;
}
/*
// 추가 설명
// 변수 이름 중복은 가능. 단 scpoe가 다르다는 한에서
Sample::Sample(int m) {
	this->m = m;		// 클래스 내의 변수에 접근: 'this'는 포인터. this로 접근해야 함
	cout << "Sample(int i) is called." << endl;
}
*/

Sample::Sample(const Sample& a) {
	// a.m++;
	m = a.getM() + 1000;		// getM에서 뭐 할지 어떻게 알아. getM을 통한 간접적 변환도 허용하지 않음
								// 헤더 파일의 getM뒤에 const를 붙임으로써 getM이 어떠한 멤버 변수에 대한 변경을 하지 않겠다는 것을 선언

	m = a.m + 1000;
}

Sample::~Sample() {
	cout << "~Sample is called." << endl;
}

void Sample::setM(int x) {
	if (x < 0) {
		throw Negative();
		m = x;
	}
}



Sample Sample::operator+(Sample& a) {
	Sample x;
	x.m = this->m + a.m;
	x.n = this->n + a.n;
	return x;
}

Sample operator-(const Sample& a, const Sample& b) {		// friend로 했기 떄문에 :: 안해줌
	Sample x;
	x.m = a.m + b.m;
	x.n = a.n + b.n;
	return x;
}


int main() {
	Sample x;				// constructor 호출
	Sample* w;				// 포인터 변수이므로 차지하는 크기 4바이트

	w = new Sample();		// constructor 호출. 동적할당을 받음. 스택이 아닌 힙에 들어감

	x.getM();			// 로컬 변수 접근
	w->getM();			// 포인터로 접근

	{
		delete w;			// destructor 호출
		Sample y;
		x.setM(2);
		// x.setM(2, 1);
		y.setM(20);
		Sample y2(y);
		Sample y3;
		y3 = y + y2 - x;
		cout << "y3.m = " << y3.getM() << endl;

		{
			Sample z(100);
			cout << "x.m = " << x.getM() << endl;
			cout << "y.m = " << y.getM() << endl;
			cout << "z.m = " << z.getM() << endl;
			cout << "y2.m = " << y2.getM() << endl;		// default copy constructor
			cout << "y3.m = " << y3.getM() << endl;
			cout << "z.sizeof = " << sizeof(z) << endl;
		}

	}

	return 0;

}

