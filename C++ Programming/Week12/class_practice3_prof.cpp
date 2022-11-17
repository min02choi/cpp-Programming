#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class Point {
	float x, y;
	
public:
	Point();
	Point(float x, float y);
	float length();
	float operator*(Point& b);		// ������ �ϳ��� this
	bool operator>(Point& b);
	friend ostream& operator << (ostream& os, const Point& p);

};

Point::Point() {
	x = 0;
	y = 0;
}


Point::Point(float x, float y) {
	this->x = x;	// ȥ�� ������ ���� this
	this->y = y;
}

float Point::length() {
	return sqrt(x * x + y * y);
}

float Point::operator*(Point& b) {
	return x * b.x + y * b.y;
}

// class_templates.cpp �� ����
// �����~~~
bool Point::operator>(Point& b) {
	if (this->x > b.x && this->y > b.y) {
		return true;
	}
	return false;
}

ostream& operator << (ostream& os, const Point& b) {
	os << "(" << b.x << ", " << b.y << ")" << endl;
	
	return os;
}

// class_templates.cpp �� �����ϱ� ���� �ּ�ó��
/*
int main() {
	Point a(2, 5);
	Point b(3, -4);

	cout << b << endl;
	cout << b.length() << endl;
	cout << (a * b) << endl;


	return 0;

}
*/