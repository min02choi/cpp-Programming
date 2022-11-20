#include <iostream>
#include <string>
#include <vector>
#include <cmath>

// 아몰랑..

using namespace std;

class Point {
protected:
	float x, y;
public:
	Point();
	Point(float x, float y);
	float length();
	float operator*(Point& b);		// 나머지 하나는 this
	friend ostream& operator << (ostream& os, const Point& p);
};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(float x, float y) {
	this->x = x;	// 혼동 방지를 위한 this
	this->y = y;
}

float Point::length() {
	return sqrt(x * x + y * y);
}

float Point::operator*(Point& b) {
	return x * b.x + y * b.y;
}

ostream& operator << (ostream& os, const Point& b) {
	os << "(" << b.x << ", " << b.y << ")" << endl;

	return os;
}

class TPoint : public Point {
private:
	float z;
public:
	TPoint();
	TPoint(float x, float y, float z);
	float length();
	friend float operator*(TPoint& b);		// 나머지 하나는 this

};

TPoint::TPoint() {
	z = 0;
}
TPoint::TPoint(float x, float y, float z) : Point(x, y){
	this->z = z;
}
float TPoint::length() {
	// return sqrt(x * x + y * y + z * z);
	return sqrt(Point::length() * Point::length() + z * z);
}
float TPoint::operator*(TPoint& b) {
	// return x * b.x + y * b.y + z * b.z;
	return ((Point)*this) * ((Point)b) + z * b.z;
}
ostream& operator << (ostream& os, const TPoint& b) {
	os << "(" << b.x << ", " << b.y << ", " << b.z << ")" << endl;

	return os;
}


int main() {
	Point a(2, 5);
	Point b(3, -4);

	cout << b << endl;
	cout << b.length() << endl;
	cout << (a * b) << endl;

	TPoint ta(2, 5, 1);
	TPoint tb(2, 5, 1);

	return 0;

}
