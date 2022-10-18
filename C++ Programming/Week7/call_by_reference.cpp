#include <iostream>
#include <vector>

using namespace std;

// 정수 관련
void test1(int a) {
	a++; 
}
void test2(int& a) {
	a++;
}

// 벡터 관련
void vec_test1(vector<int> a) {		// 여기에 const해도 에러임?
	a.push_back(100);
}
void vec_test2(vector<int>& a) {
	a.push_back(100);
}


int main() {

	// 정수 예시
	int i = 0;
	int j = 0;
	test1(i);
	test2(j);

	cout << "i: " << i << endl;
	cout << "j: " << j << endl;


	// 벡터 예시
	vector<int> a;
	vector<int> b;
	vec_test1(a);
	vec_test2(b);

	cout << "i: " << a.size() << endl;
	cout << "j: " << b.size() << endl;

	// 안전장치: const 붙이기
	// 시간이 아까우니까 참조로 보내는거지 값을 바꾸라는 얘기가 아니거든? 그래서 만약 값을 바꿀려는 시도가 있으면 컴파일러 니가 좀 막아라
	// 복사하는 시간을 절약하기 위함. 함수 안에서 조회만 하되, 수정은 못하게끔
	// 변경 시도가 있으면 컴파일러가 에러를 띄워줌
}