#include <iostream>

// status: 200
// ����: �������� n�� �Ǵ� ���� ���Ͻÿ�

/*
	<����>
	- ���� �ٸ� Ŭ������ ������ �����ε����� ��� ���� ������ �� ����?
		-> ���� �ȴٸ� �θ� �ش� �Լ� ��ġ? �ƴ� ���⼭ template ����?
	- �ڽ��� constructor�� �Ʒ��� ������� �ۿ� �ʱ�ȭ ����?
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

/* class LeftOverOne ���� */
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

/* class LeftOverTwo ���� */
LeftOverTwo::LeftOverTwo(int n) : LeftOverOne(n) {
	;
}

int LeftOverTwo::leftOver() {
	return 2;
}

/* class LeftOverOne ���� */
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
	<�����ؾ� �� ����>
	* virtual: �ش� �Լ��� ȣ���� ��ü�� �Լ��� ����ϱ� ����
	
	- ����? ��� �ϴ� �� �ľ�
	- protected �����Ұ�
	- �ڽ��� constructor ��� �����ϴ��� ����
*/