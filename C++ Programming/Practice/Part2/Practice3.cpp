#include <iostream>

// status: 200
// 문제: 나머지가 n이 되는 수를 구하시오

/*
	<질문>
	- 서로 다른 클래스를 연산자 오버로딩으로 출력 형식 지정할 수 있음?
		-> 만약 된다면 부모에 해당 함수 위치? 아니 여기서 template 쓰나?
	- 자식의 constructor은 아래의 방법으로 밖에 초기화 못함?
*/

using namespace std;

class LeftOverOne {
protected:
	int n;
	virtual int leftOver();
public:
	LeftOverOne(int n);
	int solution();
};

class LeftOverTwo : public LeftOverOne {
	virtual int leftOver();
public:
	LeftOverTwo(int n);
};

class LeftOverThree : public LeftOverTwo {
	virtual int leftOver();
public:
	LeftOverThree(int n);
};

/* class LeftOverOne 구현 */
LeftOverOne::LeftOverOne(int n) {
	this->n = n;
}

int LeftOverOne::solution() {
	int num;
	int temp = n - leftOver();
	for (int i = 2; i < temp; i++) {
		if (temp % i == 0) {
			num = i;
			return num;
		}
	}
}

int LeftOverOne::leftOver() {
	return 1;
}

/* class LeftOverTwo 구현 */
LeftOverTwo::LeftOverTwo(int n) : LeftOverOne(n) {
	;
}

int LeftOverTwo::leftOver() {
	return 2;
}

/* class LeftOverOne 구현 */
LeftOverThree::LeftOverThree(int n) : LeftOverTwo(n) {
	;
}

int LeftOverThree::leftOver() {
	return 3;
}


int main() {

	int num = 13;

	LeftOverOne leftOne(num);
	LeftOverTwo leftTwo(num);
	LeftOverThree leftThree(num);
	cout << leftOne.solution() << ", " << leftTwo.solution() << ", " << leftThree.solution() << endl;

	return 0; 
}

/*
	<주의해야 할 사항>
	* virtual: 해당 함수를 호출한 객체의 함수를 사용하기 위함
	
	- 이중? 상속 하는 법 파악
	- protected 선언할것
	- 자식의 constructor 어떻게 선언하는지 볼것
*/