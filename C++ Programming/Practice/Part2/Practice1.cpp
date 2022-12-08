#include <iostream>
#include <vector>

// status: 200
// Ŭ������ ��ü

/*
	<����>
	������ �����ε� �� �� Array ar�� ��������?
*/

// �� �ܿ��

using namespace std;

class Array {
	vector<int> arr;
public:
	Array(vector<int> arr);
	vector<int> solution();
	friend ostream& operator<<(ostream& os, Array ar);
};

/* class Array ���� */
Array::Array(vector<int> arr) {
	this->arr = arr;
}

vector<int> Array::solution() {
	vector<int> newArr;
	int bef = arr[0];
	int aft;
	newArr.push_back(bef);
	for (int i = 1; i < arr.size(); i++) {
		aft = arr[i];
		if (newArr[newArr.size() - 1] != aft) {
			newArr.push_back(aft);
		}
		
	}
	return newArr;
}

ostream& operator<<(ostream& os, Array ar) {
	for (int i = 0; i < ar.arr.size(); i++) {
		os << ar.arr[i] << " ";
	}
	os << endl;

	return os;
}

int main() {
	
	vector<int> vec = { 1, 1, 3, 3, 0, 1, 1 };
	Array arr(vec);

	cout << arr.solution() << endl;

	return 0;
}