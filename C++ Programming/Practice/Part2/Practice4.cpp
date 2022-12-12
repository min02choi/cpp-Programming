#include <iostream>
#include <string>
#include <vector>

// 문제는 3진법이지만 3진법이 아닌 n진법 상에서 돌려보자

using namespace std;

class Arithmetic {
	int n;
	int changeNum();
	string reverseNum(int newnum);
	int toDecimal(string rev);
	vector<int> changeNumRev();
	int toDecimal(vector<int> rev);
	int returnNum();
public:
	Arithmetic(int num);
	int solution();
	friend ostream& operator<<(ostream& os, Arithmetic at);
};


/* class Arithmatic 구현 */
Arithmetic::Arithmetic(int num) {
	n = num;
}

int Arithmetic::solution() {
	int newnum;
	// newnum = changeNum();	// n진법으로 변경(int)
	// string rev = reverseNum(newnum);	// 수를 뒤집음(string)
	// int answer = toDecimal(rev);

	vector<int> numList = changeNumRev();
	int answer = toDecimal(numList);
	

	return answer;
}

vector<int> Arithmetic::changeNumRev() {
	int s = returnNum();	// 진법
	int quo = n;	// '메인' 수가 될것
	int rem = 0;	// 나머지
	vector<int> vec;

	while (true) {
		if (quo < s) {
			vec.push_back(quo);
			break;
		}
		rem = quo % s;
		vec.push_back(rem);
		quo /= s;
	}

	// vector로 그냥 넘겨도 될거같은데...?

	return vec;

}

int Arithmetic::toDecimal(vector<int> rev) {
	int answer = 0;
	int s = returnNum();
	int mul = 1;

	for (int i = rev.size() - 1; i >= 0; i--) {
		answer += rev[i] * mul;
		mul *= s;
	}
	return answer;
}

int Arithmetic::returnNum() {
	return 3;
}

ostream& operator<<(ostream& os, Arithmetic at) {
	os << "10진법: " << at.n << endl;
	os << at.returnNum() << "진법으로 변경 후 뒤집고 10진법으로 표현: " << at.solution() << endl;

	return os;
}

int main() {

	Arithmetic arit(125);

	cout << arit << endl;

	return 0;

}
