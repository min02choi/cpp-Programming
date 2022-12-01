#include <iostream>
#include <string>
#include <vector>


/*
	Practice13: 행렬의 곱셈
	클래스 사용, 연산자 오버로딩
	기말고사 난이도 중하
*/

using namespace std;


/// class 선언 ///

class TDArray {
	vector<vector<int>> values;
	int getInnerProduct(TDArray ar, int i, int j);
public:
	TDArray(vector<vector<int>> v);
	TDArray operator*(TDArray ar);
	friend ostream& operator<<(ostream& os, TDArray ar);
};

/* class TDArray 구현 */
TDArray::TDArray(vector<vector<int>> v){
	values = v;
}

int TDArray::getInnerProduct(TDArray ar, int i, int j) {
	int sum = 0;
	for (int k = 0; k < values[0].size(); k++) {
		sum += values[i][k] * ar.values[k][j];
	}
	return sum;
}

TDArray TDArray::operator*(TDArray ar) {
	vector<vector<int>> v;
	for (int i = 0; i < values.size(); i++) {
		vector<int> row;
		for (int j = 0; j < ar.values[0].size(); j++) {
			row.push_back(getInnerProduct(ar, i, j));
		}
		v.push_back(row);
	}
	return TDArray(v);
}

ostream& operator<<(ostream& os, TDArray ar) {
	for (int i = 0; i < ar.values.size(); i++) {
		for (int j = 0; j < ar.values[0].size(); j++) {
			os << ar.values[i][j] << " ";
		}
		os << endl;
	}
	return os;
}

int main() {

	vector<vector<int>> v, w;
	vector<int> row;

	v = { {1, 2, 3}, {4, 5, 6} };
	w = { {1, 2}, {3, 4}, {5, 6} };

	TDArray arr1(v), arr2(w);

	cout << (TDArray(v) * TDArray(w)) << endl;
	cout << (arr1 * arr2) << endl;

	return 0;
}

// call by reference로 넘기되 const설정을 해줌
	// 안전하게 쓰고싶으면 const
// 이게 기말고사 난이도 중하 ㅋㅋㅋ
