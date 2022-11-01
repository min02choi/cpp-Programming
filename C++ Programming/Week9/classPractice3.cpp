#include <iostream>
#include "classHeader.h"		// 사용자 정의 헤더파일

/*
	destructor, 스택, 힙 등
	con
	const member function

	제대로 알 것
*/

using namespace std;

class Negative { };

Sample::Sample() {
	m = 0;
	cout << "Sample(int i) is called." << endl;
}

Sample::Sample(int x) : m{x} {		// 이런 방법도 있다~ 근데 권장하지는 않음
	// m = x;						// 걍 이게 직관적. 이거써라
	cout << "Sample(int i) is called." << endl;
}

// 추가 설명
// 변수 이름 중복은 가능. 단 scpoe가 다르다는 한에서
Sample::Sample(int m) {
	this->m = m;		// 클래스 내의 변수에 접근: 'this'는 포인터. this로 접근해야 함
	cout << "Sample(int i) is called." << endl;
}

Sample::Sample(const Sample &a) {
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

int Sample::getM() {
	return m;
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
		y3 = y;		// assignment. 오퍼레이터 오버라이딩을 해줌. 멤버 변수를 복사해줌
					// copy constructor는 최초 한번만 불리지만 assignment는 언제든 가능
					// 오퍼레이터 오버로딩

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
/*
	[강의 내용]
	# destructor

	- 자바에서는 delete권한을 사용자에게 안줌. gabage collector가 처리해줌(언제 delete될 지 알 수 없음)
	언제 사라지나?: 자신을 기억해주는 변수가 사라지면, 더 이상 자신을 access해 주는 변수가 사라지면, 메모리 leak이 되는 순간 사라짐.

	- C++에서는 메모리 leak이 되더라도 없애지 않고 프로그래머에게 맡김.
	destructor을 문법적으로 맡김
	

	- 스택에 들어가는 변수(로컬 변수)는 자신을 감싸는 가장 가까운 중괄호가 닫힐 때 사라짐
	- 힙에 들어가는 메모리는 destructor로 delete되는 순간 사라짐 

	[w]
	w 자체는 원래 포인터 변수.(local 변수) -> 자신을 감싸는 가장 가까운 중괄호가 닫힐 때 사라짐
	w는 사라지는데, w가 가리키는 주소는 사라지지 않음(힙에 메모리가 잡혀 있음)
	메모리는 잡혀있는데 그걸 기억해주는 로컬 변수가 사라짐 -> 메모리 leak

	메모리 leak를 방지하려면?
	손자들에게 그 주소를 알게 해 주어야 함

	new를 했다면 그것을 언제 delete할지는 프로그래머가 결정해야 함

	- destructor은 하나만 존재. ~클래스이름
	destructor는 뒤처리를 해줌 자기 멤버 변수중에 포인터가 있을 수 있음. 힙의 메모리를 delete해주고 죽음
	ex) 파일을 open하면 close를 해줌. 파일 도중 다른 파일을 작업했는데 본 파일을 close를 해줘야 한다면 중간에 처리하던 파일을 close하고 본인이 죽음

	- 자바에서는 class 객체에 대해서는 반드시 new를 사용해야함. 이래야지 힙에 메모리를 보낼 수 있음(?)
	선택권이 없음. 다 힙으로 감. ".", "->" 구별이 필요 없음. 다 "."으로 씀

	".": 스택
	"->": 힙
*/