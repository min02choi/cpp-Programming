#include <iostream>
#include <string>

// �̿�. �⸻���� Ŭ������ ����ϴ°� �� ���ð�

using namespace std;

class Complex {
private:
	float real;
	float img;

public:
	Complex(int num1, int num2);
	friend ostream& operator << (ostream& a, const Complex& b);
	~Complex();
};

Complex::Complex(int num1, int num2) {
	real = num1;
	img = num2;
}

ostream& operator << (ostream& a, const Complex& b) {
	
}




int main() {
	
	Complex a(2, 1);
	Complex b(2, 1);

	return 0;

}