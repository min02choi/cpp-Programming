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
	cout << "Sample() is called." << endl;
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
