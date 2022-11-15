#include <iostream>
#include <string>
#include <vector>

/*
	Abstract Base Class, virtual
*/

using namespace std;

class Polygon {
protected:
	int m, n;
public:
	Polygon(int m, int n);
	void draw();
	// virtual void draw() = 0;	// draw는 정의하지 않을 것이라는 것을 선언
};

/*
	[ virtual 함수 ]
	- 어떤 function을 호출할 지는 컴파일 떄 결정하지 말고 런타임 시에 결정하겠다는 의미
	- 바라보고 있는 오브젝트(부모꺼) 말고 현 오브젝트(ex. Rectangle)의 함수를 호출
	- 오버라이드 한 함수를 호출
	- 원래는 컴파일 링킹타임에 결정
	- 프로그래머에게 선택할 자유
	- 자바는 virtual이 default. 키워드 존재 x. 선택권이 없음
	- 수행 시간: virtual이 조금 더 느림
*/

/*
	[ virtual void draw() = 0; ]
	- 나를 상속받는 클래스는 반드시 이 함수를 가지고 있어야만 한다는 의무 부여
	- 의무적으로 구현해야 할 함수 명시
	- 상속을 항상 염두에 두고 있음
*/


// draw를 오버라이드 하지 않는 한 자기 자식 클래스도 인스턴스를 만들지 못함
class Rectangle : public Polygon {
public:
	Rectangle(int m, int n);
	void draw();		// 오버라이딩
};

class Triangle : public Polygon {
public:
	Triangle(int m, int n);
	void draw();
};

Polygon::Polygon(int m, int n) {
	this->m = m;
	this->n = n;
}


/*
void Polygon::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "*";
		}
		cout << endl;
	}	
}
*/

Rectangle::Rectangle(int m, int n) : Polygon(m, n) { }

void Rectangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

Triangle::Triangle(int m, int n) : Polygon(m, n) { }

void Triangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {

	Polygon* pol;

	int a;
	int b;
	int type;
	cin >> type >> a >> b;

	if (type == 3) {
		pol = new Triangle(a, b);
	}
	else if (type == 4) {
		pol = new Rectangle(a, b);
	}

	// Polygon pol(a, b);		// 인스턴스 생성 시도. Abstract Base Class 인 경우 불가함
	// pol.draw();

	pol->draw();		// 부모를 가리키고 있기 때문에 polygon의 draw가 호출됨
	delete pol;


	Rectangle rect(a, b);
	rect.draw();

	return 0;

}

// 클래스를 사용하면 확장성이 더 좋아짐
// Abstract Base Class: 선언은 있지만 정의가 없는(class = 0) function을 가진 클래스
// 인스턴스를 만들지 못함.

/*
	자바 abstract class 허용?
	interface: 단 하나의 멤버 함수도 정의를 가지고 있으면 안됨
*/

/*
	상속을 하면
	- 관리가 쉬워짐(상속 설계의 장점)

	[ 상속설계 ]
	C++에서는 상속설계는 오로지 프로그래머의 몫
	몇 수를 내다보는 설계를 해야 함 -> 소스코드를 유연하게 관리할 수 있음

	[ 상속설계: 자바에서는? ]
	메인도 클래스에 집어넣음 
	오브젝트를 만들지 않아도 
	static으로 메인 function으로 시작함
	태초의 상속이 있음. 컴파일러가 디폴트로 상속을 시킴.
	object class는 모든 클래스의 디폴트 클래스
*/
