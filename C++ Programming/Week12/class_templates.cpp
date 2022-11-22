#include <iostream>
#include <string>
#include <vector>
#include "class_practice3_prof.cpp"

/*
	Template
	�� �ڵ忡���� ��Һ񱳰� �� �Ǵ��İ� �ٽ���
	- ��Һ񱳰� �Ǵ� Ÿ���� �Է�
	- user defined�̸� operation overloading�� ���־�� ��
*/

using namespace std;

template <class T>
class myPair {
	T a, b;
public:
	myPair(T first, T second) {
		a = first;
		b = second;
	}
	T getMax();
};

template <class T>
T myPair<T>::getMax() {
	T retval;
	retval = a > b ? a : b;
	return retval;
}

int main() {
	myPair<int> myObjectInt(100, 75);
	cout << myObjectInt.getMax() << endl;

	myPair<float> myObjectFloat(75.2, 100.04);
	cout << myObjectFloat.getMax() << endl;
	
	// ��? ��...
	// myPair<Point> myObjectPoint(Point(1, 2), Point(3, 4));
	// cout << myObjectPoint.getMax() << endl;

	return 0;
}

/*
	������ ����� �ʿ�� �ϴµ� �ڷ����� �ٸ� ��찡 ����
	�ڷᱸ���� ���� ȿ�������� �����ϱ� ���� ����
	Ÿ���� ����� �����

*/