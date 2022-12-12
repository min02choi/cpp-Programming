#include <iostream>
#include <string>
#include <vector>

// status: 200
// 이해도(10점 만점): 10

/*
	하나의 부모를 여러 자식들이 상속
	virtual 함수
*/

/*
	- virtual void draw() = 0; 사용 시 부모클래스에서는 함수 선언 할 필요가 없음. 대신 자식에서 오버라이딩 해주어야함
	- 부모는 '다각형'클래스. 자식들은 사각형, 삼각형 클래스. 부모에 값과 draw함수를 저장하고 자식에서 이를 이용, draw()를 구현
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

/* class Polygon 구현 */
Polygon::Polygon(int w, int h) {
	width = w;
	height = h;
}

/* class Rectangle 구현 */
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

/* class Triangle 구현 */
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