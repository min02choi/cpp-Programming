#include <iostream>
#include "operatorOverloading.h"		// ����� ���� �������

// ���� �ȵ��ư�

using namespace std;

// class Negative { };

Sample::Sample() {
	m = 0;
	cout << "Sample(int i) is called." << endl;
}

Sample::Sample(int x) : m{ x } {		// �̷� ����� �ִ�~ �ٵ� ���������� ����
	m = x;						// �� �̰� ������. �̰Ž��
	cout << "Sample(int i) is called." << endl;
}
/*
// �߰� ����
// ���� �̸� �ߺ��� ����. �� scpoe�� �ٸ��ٴ� �ѿ���
Sample::Sample(int m) {
	this->m = m;		// Ŭ���� ���� ������ ����: 'this'�� ������. this�� �����ؾ� ��
	cout << "Sample(int i) is called." << endl;
}
*/

Sample::Sample(const Sample& a) {
	// a.m++;
	m = a.getM() + 1000;		// getM���� �� ���� ��� �˾�. getM�� ���� ������ ��ȯ�� ������� ����
								// ��� ������ getM�ڿ� const�� �������ν� getM�� ��� ��� ������ ���� ������ ���� �ʰڴٴ� ���� ����

	m = a.m + 1000;
}

Sample::~Sample() {
	cout << "~Sample is called." << endl;
}

void Sample::setM(int x) {
	if (x < 0) {
		throw Negative();
		m = x;
	}
}



Sample Sample::operator+(Sample& a) {
	Sample x;
	x.m = this->m + a.m;
	x.n = this->n + a.n;
	return x;
}

Sample operator-(const Sample& a, const Sample& b) {		// friend�� �߱� ������ :: ������
	Sample x;
	x.m = a.m + b.m;
	x.n = a.n + b.n;
	return x;
}


int main() {
	Sample x;				// constructor ȣ��
	Sample* w;				// ������ �����̹Ƿ� �����ϴ� ũ�� 4����Ʈ

	w = new Sample();		// constructor ȣ��. �����Ҵ��� ����. ������ �ƴ� ���� ��

	x.getM();			// ���� ���� ����
	w->getM();			// �����ͷ� ����

	{
		delete w;			// destructor ȣ��
		Sample y;
		x.setM(2);
		// x.setM(2, 1);
		y.setM(20);
		Sample y2(y);
		Sample y3;
		y3 = y + y2 - x;
		cout << "y3.m = " << y3.getM() << endl;

		{
			Sample z(100);
			cout << "x.m = " << x.getM() << endl;
			cout << "y.m = " << y.getM() << endl;
			cout << "z.m = " << z.getM() << endl;
			cout << "y2.m = " << y2.getM() << endl;		// default copy constructor
			cout << "y3.m = " << y3.getM() << endl;
			cout << "z.sizeof = " << sizeof(z) << endl;
		}

	}

	return 0;

}

