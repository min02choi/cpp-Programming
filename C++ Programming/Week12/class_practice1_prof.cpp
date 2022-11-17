#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Complex {
	float a, b;
public:
	Complex();
	Complex(float a, float b);
	Complex operator+(Complex &);
	friend ostream& operator << (ostream& os, const Complex& c);
};

Complex::Complex() {
	a = 0;
	b = 0;
}

Complex::Complex(float a, float b) {
	this->a = a;
	this->b = b;
}

// "+"에 대한 오퍼레이터 오버로딩
Complex Complex::operator+(Complex& b) {
	Complex c;
	c.a = this->a + b.a;
	c.b = this->b + b.b;

	return c;
}

ostream& operator << (ostream& os, const Complex& c) {
	if (c.a != 0) {
		os << c.a;
	}
	if (c.b < 0) {
		os << " - " << -c.b << "i";
	}
	else if (c.b < 0) {
		os << " + " << c.b << "i";
	}
	return os;
}


int main() {
	Complex a(2, 1);
	Complex b(3, -4);

	cout << (a + b) << endl;

	return 0;
}

/*
	오퍼레이션 오버로딩을 하면 확장가능성이 있음. 우아함
*/