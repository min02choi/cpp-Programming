#include <iostream>
#include <string>
#include <vector>

// 문제: SevenSegment 구현
/*
	하나의 SevenSegment를 저장하는 class SevenSeg, SevenSeg class를 저장하는 SevenSegs 클래스
*/

using namespace std;

class SevenSegs;

class SevenSeg {
	int n;
	char seg[5][3];
	void setSeg();
public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
};

class SevenSegs {
	int n;
	vector<SevenSeg> allSegs;
public:
	SevenSegs(int n);
	friend ostream& operator<<(ostream& os, SevenSegs& sss);
};

/* Class SevenSeg 구현 */
SevenSeg::SevenSeg(int n) {
	this->n = n;
	setSeg();
}

void SevenSeg::setSeg() {
	seg[0][0] = ' ';
	seg[0][2] = ' ';
	seg[1][1] = ' ';
	seg[2][0] = ' ';
	seg[2][2] = ' ';
	seg[3][1] = ' ';
	seg[4][0] = ' ';
	seg[4][2] = ' ';

	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[0][1] = '-'; else seg[0][1] = ' ';
	if (n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[1][0] = '|'; else seg[1][0] = ' ';
	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 || n == 0) seg[1][2] = '|'; else seg[1][2] = ' ';
	if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) seg[2][1] = '-'; else seg[2][1] = ' ';
	if (n == 2 || n == 6 || n == 8 || n == 0) seg[3][0] = '|'; else seg[3][0] = ' ';
	if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[3][2] = '|'; else seg[3][2] = ' ';
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) seg[4][1] = '-'; else seg[4][1] = ' ';
}

ostream& operator<<(ostream& os, SevenSeg& ss) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			os << ss.seg[i][j];
		}
		os << endl;
	}
	return os;
}

/* Class SevenSegs 구현 */
SevenSegs::SevenSegs(int n) {
	this->n = n;
	for (int i = n; i > 0;) {
		SevenSeg temp(i % 10);
		allSegs.push_back(temp);
		i /= 10;
	}
}

ostream& operator<<(ostream& os, SevenSegs& sss) {
	for (int i = 0; i < 5; i++) {
		for (int j = sss.allSegs.size() - 1; j >= 0; j--) {
			for (int k = 0; k < 3; k++) {
				os << sss.allSegs[j].seg[i][k];
			}
		}
		os << endl;
	}
	return os;
}

int main() {

	SevenSeg ss(8);
	SevenSegs sss(12345);

	cout << ss << endl;
	cout << sss << endl;

	return 0;
}