#include <iostream>
#include <string>
#include <vector>

// status: 200
// ���ص�(10�� ����): 10

/*
	�ϳ��� �θ� ���� �ڽĵ��� ���
	virtual �Լ�
*/

/*
	- virtual void draw() = 0; ��� �� �θ�Ŭ���������� �Լ� ���� �� �ʿ䰡 ����. ��� �ڽĿ��� �������̵� ���־����
	- �θ�� '�ٰ���'Ŭ����. �ڽĵ��� �簢��, �ﰢ�� Ŭ����. �θ� ���� draw�Լ��� �����ϰ� �ڽĿ��� �̸� �̿�, draw()�� ����
*/

using namespace std;

class Polygon {
protected:
	int width;
	int height;
public:
	Polygon(int w, int h);
	// virtual int draw();
	virtual void draw() = 0;
};

class Rectangle : public Polygon {
public:
	Rectangle(int w, int h);
	void draw();
};

class Triangle : public Polygon {
public:
	Triangle(int w, int h);
	void draw();
};

/* class Polygon ���� */
Polygon::Polygon(int w, int h) {
	width = w;
	height = h;
}

/* class Rectangle ���� */
Rectangle::Rectangle(int w, int h) : Polygon(w, h) {
	;
}

void Rectangle::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

/* class Triangle ���� */
Triangle::Triangle(int w, int h) : Polygon(w, h) {
	;
}

void Triangle::draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < i + 1; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {
	Rectangle rect(5, 3);
	rect.draw();

	Triangle tri(5, 3);
	tri.draw();

	return 0;
}