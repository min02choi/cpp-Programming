#include <iostream>
#include <string>
#include <vector>

/*
	Abstract Base Class, virtual
*/

using namespace std;

class Polygon {
protected:
	int m, n;
public:
	Polygon(int m, int n);
	void draw();
	// virtual void draw() = 0;	// draw�� �������� ���� ���̶�� ���� ����
};

/*
	[ virtual �Լ� ]
	- � function�� ȣ���� ���� ������ �� �������� ���� ��Ÿ�� �ÿ� �����ϰڴٴ� �ǹ�
	- �ٶ󺸰� �ִ� ������Ʈ(�θ�) ���� �� ������Ʈ(ex. Rectangle)�� �Լ��� ȣ��
	- �������̵� �� �Լ��� ȣ��
	- ������ ������ ��ŷŸ�ӿ� ����
	- ���α׷��ӿ��� ������ ����
	- �ڹٴ� virtual�� default. Ű���� ���� x. ���ñ��� ����
	- ���� �ð�: virtual�� ���� �� ����
*/

/*
	[ virtual void draw() = 0; ]
	- ���� ��ӹ޴� Ŭ������ �ݵ�� �� �Լ��� ������ �־�߸� �Ѵٴ� �ǹ� �ο�
	- �ǹ������� �����ؾ� �� �Լ� ���
	- ����� �׻� ���ο� �ΰ� ����
*/


// draw�� �������̵� ���� �ʴ� �� �ڱ� �ڽ� Ŭ������ �ν��Ͻ��� ������ ����
class Rectangle : public Polygon {
public:
	Rectangle(int m, int n);
	void draw();		// �������̵�
};

class Triangle : public Polygon {
public:
	Triangle(int m, int n);
	void draw();
};

Polygon::Polygon(int m, int n) {
	this->m = m;
	this->n = n;
}


/*
void Polygon::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "*";
		}
		cout << endl;
	}	
}
*/

Rectangle::Rectangle(int m, int n) : Polygon(m, n) { }

void Rectangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

Triangle::Triangle(int m, int n) : Polygon(m, n) { }

void Triangle::draw() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}
}

int main() {

	Polygon* pol;

	int a;
	int b;
	int type;
	cin >> type >> a >> b;

	if (type == 3) {
		pol = new Triangle(a, b);
	}
	else if (type == 4) {
		pol = new Rectangle(a, b);
	}

	// Polygon pol(a, b);		// �ν��Ͻ� ���� �õ�. Abstract Base Class �� ��� �Ұ���
	// pol.draw();

	pol->draw();		// �θ� ����Ű�� �ֱ� ������ polygon�� draw�� ȣ���
	delete pol;


	Rectangle rect(a, b);
	rect.draw();

	return 0;

}

// Ŭ������ ����ϸ� Ȯ�强�� �� ������
// Abstract Base Class: ������ ������ ���ǰ� ����(class = 0) function�� ���� Ŭ����
// �ν��Ͻ��� ������ ����.

/*
	�ڹ� abstract class ���?
	interface: �� �ϳ��� ��� �Լ��� ���Ǹ� ������ ������ �ȵ�
*/

/*
	����� �ϸ�
	- ������ ������(��� ������ ����)

	[ ��Ӽ��� ]
	C++������ ��Ӽ���� ������ ���α׷����� ��
	�� ���� ���ٺ��� ���踦 �ؾ� �� -> �ҽ��ڵ带 �����ϰ� ������ �� ����

	[ ��Ӽ���: �ڹٿ�����? ]
	���ε� Ŭ������ ������� 
	������Ʈ�� ������ �ʾƵ� 
	static���� ���� function���� ������
	������ ����� ����. �����Ϸ��� ����Ʈ�� ����� ��Ŵ.
	object class�� ��� Ŭ������ ����Ʈ Ŭ����
*/
