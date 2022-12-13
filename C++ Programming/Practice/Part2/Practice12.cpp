#include <iostream>
#include <string>
#include <vector>

// status: 200
// 이해도: 9

/*
	- 마스크 사용하는 방법 다시 볼 것!	
*/

/*
	12번 문제를 살짝 변형해서 일단은 숫자 하나를 넣으면 비트 2개까지 다른 수가 나옴
	입력값 vector로도 한번 해볼 것
	#class, #상속
*/

/*
	[구현 방법]
	solution에서 다른 함수들을 부름 -> solution은 public, 그 외의 함수들은 private
*/

/*
	질문
	비트연산자를 그냥 10진수에다 쓰면 반영이 됨?
	니가해봐라
	넵
*/

using namespace std;

/////////////// 클래스 선언 ///////////////////////////

// 비트 다름 2개까지 허용
class Practice12 {
protected:
	long long n;
	int difference(long long n, long long i);
	virtual int limit();
public:
	Practice12(long long a);
	long long solution();
};

// 비트 다름 3개까지 허용
class Practice12_2 : public Practice12 {
	virtual int limit();	// virtual 부모에만 해줘도 됨
public:
	Practice12_2(long long a);
};

///////////// 클래스 구현 ///////////////////

/* class Practice12 구현 */
Practice12::Practice12(long long a) {
	this->n = a;
}

// 두 개의 정수를 받아 비트를 비교하고 다른 자리의 갯수를 반환
// 비트마스크 사용. 와 근데 진짜 천잰가 와 와
int Practice12::difference(long long n, long long i) {
	int count = 0;
	int len = sizeof(n) * 8;		// 질문
	long long mask = 1;
	for (int j = 0; j < len; j++) {
		if ((n & mask) != (i & mask)) {
			count++;
		}
		mask = mask << 1;
	}
	return count;
}

int Practice12::limit() {
	return 2;
}

long long Practice12::solution() {
	int dif;
	int ans;
	for (int i = n + 1; ; i++) {
		dif = difference(n, i);
		if (dif >= 1 && dif <= limit()) {
			ans = i;
			// break;
			return ans;
		}
	}
	return ans;
}

/* class Practice12_2 구현 */
Practice12_2::Practice12_2(long long a) : Practice12(a){
	;
	// n = a;
	// Practice12(a);
	// 질문: 초기화 방법 이뿐?
}

int Practice12_2::limit() {
	return 3;
}



int main() {

	vector<long long> num;		// 아직 덜함
	num = { 2, 7 };

	Practice12 p12(7);
	cout << p12.solution() << endl;

	Practice12_2 p12_2(7);
	cout << p12_2.solution() << endl;

	return 0;
}

// 클래스 사용, 연산자 오버로딩, 상속