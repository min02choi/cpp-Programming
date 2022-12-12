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
	virtual int leftOver() {
		return 1;
	}

public:
	~LeftOverOne() { cout << "�Ҹ���1\n"; }
	LeftOverOne(int n=0) {
		cout << "������1\n";
		this->n = n;
	}

	int solution() {
		int num;
		int temp = n - leftOver();
		for (int i = 2; i < temp; i++) {
			if (temp % i == 0) {
				num = i;
				return num;
			}
		}
	}

};

class LeftOverTwo : public LeftOverOne {
	int leftOver() {
		return 2;
	}
public:
	~LeftOverTwo() { cout << "�Ҹ���2\n"; }
	LeftOverTwo(int n) : LeftOverOne(n) {
		cout << "������2\n";
	}
};

class LeftOverThree : public LeftOverTwo {
	int leftOver() {
		return 3;
	}
public:
	~LeftOverThree() { cout << "�Ҹ���3\n"; }
	LeftOverThree(int n) : LeftOverTwo(n) {
		cout << "������3\n";
	}
};

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