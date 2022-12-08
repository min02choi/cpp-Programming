#include <iostream>
#include <vector>


// 아니 뭐가 문제임 디버깅도 하  하 하 하 하나씩 보기 머리아프다 이따가 하자

using namespace std;


class Matrix {
	vector<vector<int>> v;
public:
	Matrix(vector<vector<int>> v);
	Matrix operator*(Matrix m);
	friend ostream& operator<<(ostream& os, Matrix mt);
};

/* class Matrix 구현 */
Matrix::Matrix(vector<vector<int>> v) {
	this->v = v;
}

Matrix Matrix::operator*(Matrix m) {
	int sum = 0;
	vector<vector<int>> vec;
	for (int row = 0; row < v.size(); row++) {
		vector<int> temp;
		for (int h = 0; h < m.v[0].size(); h++) {
			sum = 0;
			for (int i = 0; i < v[0].size(); i++) {
				sum += v[h][i] * m.v[i][h];
			}
			temp.push_back(sum);
			// sum = 0;
		}
		vec.push_back(temp);
	}
	return Matrix(vec);
}

ostream& operator<<(ostream& os, Matrix mt) {
	for (int i = 0; i < mt.v.size(); i++) {
		for (int j = 0; j < mt.v[0].size(); j++) {
			os << mt.v[i][j] << " ";
		}
		os << endl;
	}
	return os;
}


int main() {

	vector<vector<int>> v1, v2;

	v1 = { {1, 2, 3}, {4, 5, 6} };
	v2 = { {1, 2}, {3, 4}, {5, 6} };

	Matrix m1(v1), m2(v2);

	cout << m1 * m2 << endl;

	return 0;

}