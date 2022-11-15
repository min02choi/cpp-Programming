#include <iostream>
#include <string>
#include <vector>

// �� �ڵ� �ٽ� �����ϼ�

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
	virtual ~Polygon();		// ��Ӱ��踦 ���ο� �дٸ� destructor�� virtual�� �ϴ� ���� ���
	// virtual void draw() = 0;
};
/*
	
*/

class Rectangle : public Polygon {
public:
	Rectangle(int m, int n);
	~Rectangle();
	void draw();		// �������̵�
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


	pol->draw();		// �θ� ����Ű�� �ֱ� ������ polygon�� draw�� ȣ���
	delete pol;


	Rectangle rect(a, b);
	rect.draw();

	return 0;

}
