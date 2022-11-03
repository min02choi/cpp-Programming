// static members in classes

#include <iostream>

/*
	class안의 static 변수에 대해서
	static 멤버 함수
*/

using namespace std;

class CDummy {
	public:
		static int n;		// 클래스에 속해 멤버 변수를 공유
		int m;

		CDummy() {
			// n = 0;		// 여기서 초기화를 하면 객체가 생성될 때마다 초기화됨
			n++;
		};
		~CDummy() {	
			n--;
		};
		static int getN() {			// static는 this라는 개념이 없음
			// return n + m;		// 함수가 static임 (누구의) m인지 특정할 수 없음. m은 object에 종속적
			return n;
		}
		int getM() {
			return n + m;			// 문제없음
		}
};

// static 변수 초기화는 이런 식으로 함
int CDummy::n = 0;			// 바깥에다 꺼내서 초기화. 딱 한번 실행

int main() {

	// CDummy::getM();
	// getN()

	CDummy a;				// 스택, 1개 생성, 총 6개
	CDummy b[5];			// 스택, 5개 생성, 총 6개
	CDummy* c = new CDummy;	// 힙, 1개 생성, 총 7개

	// 위 과정에서 n이 7번 호출되었으므로 n = 7
	cout << a.n << endl;

	delete c;	// 하나가 사라짐

	cout << CDummy::n << endl;		// 얘는 static변수라는것을 명시함 (a.n도 가능)

	// 번외: 크기 관련
	// 일반적으로 멤버 함수에 포함X object에 속하는게 아니라 class에 속하는 것이므로.
	// 따라서 static로 선언을 해준 변수에 대해서는 sizeof를 하지 않음.
	// 만약 다른 static이 아닌 변수가 있으면 해당 object의 크기는 static이 아닌 변수의 크기로 출력.
	// static변수만 있을 때는 크기를 "1"이라고 정의
	cout << sizeof(a) << endl;
	
	return 0;
}