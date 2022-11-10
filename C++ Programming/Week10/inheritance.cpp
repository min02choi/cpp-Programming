#include <iostream>

/*
	상속
	protected, private
*/

using namespace std;

class CPolygon {
	protected:
		int width, height;
	public:
		void set_values(int a, int b) {
			width = a;
			height = b;
		}
};

class CRectangle : public CPolygon {
	public:
		int area() {
			return (width * height);
		}
};

class CTriangle : public CPolygon {
	public:
		int area() {
			return (width * height / 2);
		}
};

int main() {

	CRectangle rect;
	CTriangle trgl;

	rect.set_values(4, 5);		// CPolygon으로부터 상속 받았기 떄문에 함수 사용 가능
	trgl.set_values(4, 5);

	cout << rect.area() << endl;
	cout << trgl.area() << endl;

	return 0;

}

// 상속: 동일한 기능을 재 정의 할 필요가 없다는 장점