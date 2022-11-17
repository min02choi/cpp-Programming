#include <iostream>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

class Point {
	float x, y;
	float ans;
public:
	Point();
	Point(float n1, float n2);
	float operator*(Point&);
	float length();
	friend ostream& operator << (ostream& os, const Point& p);

};

Point::Point() {
	x = 0;
	y = 0;
}

Point::Point(float n1, float n2) {
	this->x = n1;
	this->y = n2;
}

float Point::operator*(Point& np) {
	Point p;
	p.x = this->x * np.x;
	p.y = this->y * np.y;

	return p.x + p.y;
}

ostream& operator << (ostream& os, const Point& p) {
	os << "(" << sqrt();
}


int main() {
	Point a(3, 5);

	return 0;

}

// 12.13(ȭ): �⸻