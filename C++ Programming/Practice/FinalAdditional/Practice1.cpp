#include <iostream>
#include <string>
#include <vector>

/*
	Seven Segment 구현
*/


using namespace std;

class SevenSegs;

class SevenSeg {
	int n;
	char seg[15];
	void Set();
public:
	SevenSeg(int n);
	friend ostream& operator<<(ostream& os, SevenSeg& ss);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
};

class SevenSegs {
	int n;
	vector<SevenSeg> segs;
	void Set();
public:
	SevenSegs(int n);
	friend ostream& operator<<(ostream& os, SevenSegs& ss);
};


/* class SevenSeg 구현 */
void SevenSeg::Set() {
	seg[0] = ' ';
	seg[2] = ' ';
	seg[4] = ' ';
	seg[6] = ' ';
	seg[8] = ' ';
	seg[10] = ' ';
	seg[12] = ' ';
	seg[14] = ' ';
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[1] = '-'; else seg[1] = ' ';
	if (n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[3] = '|'; else seg[3] = ' ';
	if (n == 1 || n == 2 || n == 3 || n == 4 || n == 7 || n == 8 || n == 9 || n == 0) seg[5] = '|'; else seg[5] = ' ';
	if (n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 8 || n == 9) seg[7] = '-'; else seg[7] = ' ';
	if (n == 2 || n == 6 || n == 8 || n == 0) seg[9] = '|'; else seg[9] = ' ';
	if (n == 1 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8 || n == 9 || n == 0) seg[11] = '|'; else seg[11] = ' ';
	if (n == 2 || n == 3 || n == 5 || n == 6 || n == 8 || n == 9 || n == 0) seg[13] = '-'; else seg[13] = ' ';

}

SevenSeg::SevenSeg(int n) {
	this->n = n;
	Set();
}

ostream& operator<<(ostream& os, SevenSeg& ss) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			os << ss.seg[k++];
		}
		os << endl;
	}
	return os;
}


/* class SevenSegs 구현 */
void SevenSegs::Set() {
	for (int k = n; k > 0; k = k / 10) {
		SevenSeg temp(k % 10);
		segs.push_back(temp);
	}
}

SevenSegs::SevenSegs(int n) {
	this->n = n;
	Set();
}

ostream& operator<<(ostream& os, SevenSegs& ss) {
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = ss.segs.size() - 1; j >= 0; j--) {
			for (int w = 0; w < 3; w++) {
				os << ss.segs[j].seg[k + w];
			}
		}
		k += 3;
		os << endl;
	}
	return os;
}

int main() {
	// SevenSeg myseg1(1), myseg2(2), myseg3(3), myseg4(4), myseg5(5), myseg6(6), myseg7(7), myseg8(8), myseg9(9), myseg0(0);
	// cout << myseg1 << myseg2 << myseg3 << myseg4 << myseg5 << myseg6 << myseg7 << myseg8 << myseg9 << myseg0 << endl;

	SevenSegs mysegs(10965);
	cout << mysegs << endl;

	return 0;
}