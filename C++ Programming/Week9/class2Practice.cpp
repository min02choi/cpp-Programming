#include <iostream>

using namespace std;

class Negative { };

class Sample {

private:		// default. 선언 안해주어도 됨
	int m;

public:
	int n;
	Sample();		// constructor. class이름과 같아야 함
	Sample(int x);
	int getM();


	void setM(int x) {
		if (x < 0) throw Negative();
		m = x;
	}
	int getM() {
		return m;
	}
};
Sample::Sample() {
	m = x;
	cout << "Sample(int i) is called." << endl;
}
Sample::Sample(int x) {
	m = x;
	cout << "Sample(int i) is called." << endl;
}
void Sample::setM(int x) {
	if (x < 0) {
		throw Negative();
		m = x;
	}
}
int Sample::getM() {
	return m;
}

int main() {
	Sample x, y, z(100);

	x.setM(2);		// class내부에 있는 함수를 통해 우회적으로 m접근
	y.setM(20);

	cout << "x.m = " << x.getM() << endl;
	cout << "y.m = " << y.getM() << endl;
	cout << "z.m = " << z.getM() << endl;

	return 0;

}

/*
	constructor -> class를 호출할 때 자동적으로 호출됨
	class를 호출 할 때 default constructor호출, 선언 안해도 됨
	default constructor이 없다면 컴파일러가 자동으로 만들어줌
	하지만 default constructor이 없고 사용자가 정의한 것만 만들었다면 매개변수가 없는 constructor을 사용하려면 default constructor을 따로 지정해줘야함
	다형성:	constructor의 파라매터의 개수나 type를 달리하면 중복된 이름으로 여러개의 constructor를 사용할 수 있음
*/
