#include <iostream>
#include <string>
#include <vector>

// 응 코드 다시 수정하셈

/*
	destructor
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
/*
	
*/

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


	pol->draw();		// 부모를 가리키고 있기 때문에 polygon의 draw가 호출됨
	delete pol;


	Rectangle rect(a, b);
	rect.draw();

	return 0;

}
