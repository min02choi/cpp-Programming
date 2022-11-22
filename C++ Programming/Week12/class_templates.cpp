#include <iostream>
#include <string>
#include <vector>
#include "class_practice3_prof.cpp"

/*
	Template
	이 코드에서는 대소비교가 잘 되느냐가 핵심임
	- 대소비교가 되는 타입을 입력
	- user defined이면 operation overloading을 해주어야 함
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
	
	// 응? 하...
	// myPair<Point> myObjectPoint(Point(1, 2), Point(3, 4));
	// cout << myObjectPoint.getMax() << endl;

	return 0;
}

/*
	동일한 기능을 필요로 하는데 자료형이 다른 경우가 많음
	자료구조를 보다 효율적으로 적용하기 위해 도입
	타입을 대명사로 비워둠

*/