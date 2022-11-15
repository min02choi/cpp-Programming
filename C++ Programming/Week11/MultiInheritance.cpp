#include <iostream>
#include <string>
#include <vector>

/*
	다중상속
*/

using namespace std;

class Polygon {
protected:
	int m, n;
public:
	Polygon(int m, int n);
	void draw();
	virtual ~Polygon();		// 상속관계를 염두에 둔다면 destructor은 virtual로 하는 것이 상식
	// virtual void draw() = 0;
};

class Rectangle : public Polygon {
public:
	Rectangle(int m, int n);
	~Rectangle();
	void draw();		// 오버라이딩
};

class Triangle : public Polygon {
public:
	Triangle(int m, int n);
	~Triangle();
	void draw();
};

// 다중 상속
// string과 Rectangle을 동시에 상속받음
class MyMulti : public string, public Rectangle {
public:
	MyMulti(int m, int n, const char* str);
};


Polygon::Polygon(int m, int n) {
	this->m = m;
	this->n = n;
}

Polygon::~Polygon() {
	cout << "Polygon::~Polygon()";
}


Rectangle::Rectangle(int m, int n) : Polygon(m, n) { }

Rectangle::~Rectangle() {
	cout << "Rectangle::~Rectangle()";
}

void Rectangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

Triangle::Triangle(int m, int n) : Polygon(m, n) { }

Triangle::~Triangle() {
	cout << "Triangle::~Triangle()";
}

void Triangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

MyMulti::MyMulti(int m, int n, const char* str) : Rectangle(m, n), string(str) {

}


int main() {
	/*
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

	pol->draw();		// 부모를 가리키고 있기 때문에 polygon의 draw가 호출됨
	delete pol;

	Rectangle rect(a, b);
	rect.draw();
	*/

	MyMulti test(5, 3, "abc");
	test.draw();

	cout << test << endl;
	cout << test[2] << endl;

	return 0;

}

/*
	[ 다중상속이 가지는 단점? ]
	- 내가 상속을 받으려는 멤버함수나 변수의 이름이 같은 경우 혼동 발생
	- 이 문제점을 내포하고 있음
		
	-> 문법적 자유는 허락할 테니 이로 인해서 발생하는 문제점은 본인이 책임져라


	[ 자바에서는? ]
	- 자바에서는 다중 상속을 지원하지 않음
	- interface는 멤버 변수는 허용이 안됨(얘는 적자마자 정의임), 멤버 함수만 있음
	- implement - interface를 implement하라~ interface는 multiple 가능
	- class 는 다중상속 X
	
*/
