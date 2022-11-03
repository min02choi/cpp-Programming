#include <iostream>

/*
	스택과 힙 저장시 메모리 삭제 법
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

	CRectangle a, * b, * c;		// a만 CRectangle이 메모리(스택)에 잡혀있음, b, c는 포인터에 대한 메모리가 잡혀있음
	CRectangle* d = new CRectangle[2];	// 추가로 두개는 힙(array이므로 연속된 주소공간)에 잡혀있음, CRectangle 세네개
	b = new CRectangle;		// CRectangle 총네개
	c = &a;					// 스택의 주소를 가리키는 포인터 c는 스택을 가리키게 됨

	// CRectangle생성 결과: 스택에 하나, 힙에 세개

	a.set_values(1, 2);
	b->set_values(3, 4);
	d->set_values(5, 6);		// d->와 d[0]. 은 똑같은 것
	d[1].set_values(7, 8);		// 원소로 접근할 때에는 "."로 접근

	cout << "a area: " << a.area() << endl;
	cout << "*b area: " << b->area() << endl;
	cout << "*c area: " << c->area() << endl;
	cout << "d[0] area: " << d[0].area() << endl;
	cout << "d[1] area: " << d[1].area() << endl;

	// 스택에 있는 a는 중괄호가 닫히면 자동으로 사라짐
	// 힙에 있는 요소들에 대해 메모리 delete 수행
	delete [] d;		// d는 array이기 때문에 []반드시 기입. 안쓰면 0번만 날림. 
	delete b;

	return 0;
}