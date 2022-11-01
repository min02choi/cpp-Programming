#include <iostream>

using namespace std;

class Negative { };

class Sample {

	private:		// default. 선언 안해주어도 됨
		int m;

	public:

		int n;	// 외부에서 바꿔도 제어할 방법이 없음

		void setM(int x) {
			if (x < 0) throw Negative();	// 권장되는 방식
			m = x;
		}
		int getM() {
			return m;
		}
};

int main() {
	Sample x, y;
	x.n = 1;
	y.n = 10;
	// x.m = 1;		// Error: m은 private이므로 접근 불가
	// y.m = 10;	// Error: m은 private이므로 접근 불가
	x.setM(2);		// class내부에 있는 함수를 통해 우회적으로 m접근
	y.setM(20);

	cout << "x.n = " << x.n << endl;
	cout << "y.n = " << y.n << endl;

	cout << "x.m = " << x.getM() << endl;
	cout << "y.m = " << y.getM() << endl;

}

/*
	n, m의 접근 방식 중 m방식이 더 선호됨.
	m방식을 사용하는 경우 함수를 통해서 데이터 변경에 대해 한 번 더 감시할 수 있는 기회가 됨.
	위 코드의 경우, m이 음수가 되면 안되는 경우(가정), 함수 내에서 한번 모니터링 가능.

	크기? member변수에 따라 크기가 정해짐
*/