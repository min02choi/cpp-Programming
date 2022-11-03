#include <iostream>

/*
	���ð� �� ����� �޸� ���� ��
	delete
	".", "->" 
*/

using namespace std;

class CRectangle {
	int width, height;

	public:
		void set_values(int, int);
		int area(void) {
			return (width * height);
		}
};
void CRectangle::set_values(int a, int b) {
	width = a;
	height = b;
}

int main() {

	CRectangle a, * b, * c;		// a�� CRectangle�� �޸�(����)�� ��������, b, c�� �����Ϳ� ���� �޸𸮰� ��������
	CRectangle* d = new CRectangle[2];	// �߰��� �ΰ��� ��(array�̹Ƿ� ���ӵ� �ּҰ���)�� ��������, CRectangle ���װ�
	b = new CRectangle;		// CRectangle �ѳװ�
	c = &a;					// ������ �ּҸ� ����Ű�� ������ c�� ������ ����Ű�� ��

	// CRectangle���� ���: ���ÿ� �ϳ�, ���� ����

	a.set_values(1, 2);
	b->set_values(3, 4);
	d->set_values(5, 6);		// d->�� d[0]. �� �Ȱ��� ��
	d[1].set_values(7, 8);		// ���ҷ� ������ ������ "."�� ����

	cout << "a area: " << a.area() << endl;
	cout << "*b area: " << b->area() << endl;
	cout << "*c area: " << c->area() << endl;
	cout << "d[0] area: " << d[0].area() << endl;
	cout << "d[1] area: " << d[1].area() << endl;

	// ���ÿ� �ִ� a�� �߰�ȣ�� ������ �ڵ����� �����
	// ���� �ִ� ��ҵ鿡 ���� �޸� delete ����
	delete [] d;		// d�� array�̱� ������ []�ݵ�� ����. �Ⱦ��� 0���� ����. 
	delete b;

	return 0;
}