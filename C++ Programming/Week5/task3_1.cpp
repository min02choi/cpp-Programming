#include <string>
#include <vector>
#include <iostream>

/*
	�� 4���� �Է¹ް� �ش� �簢���� ���̸� ���϶�
	(��, ���簢���� ����� �ƴ� ��ǥ�� �Էµ��� �ʴ´�.)
*/


using namespace std;

// ������ Ǯ��
int getDiff(vector<vector<int>> dots, int dim) {
	int max, min;
	max = -256;		// ���� �� �� ���� ��
	min = -256;

	for (int i = 0; i < dots.size(); i++) {
		if (max < dots[i][dim]) {
			max = dots[i][dim];
		}
		if (min > dots[i][dim]) {
			min = dots[i][dim];
		}
	}
	return max - min;
}

int professor_solution(vector<vector<int>> dots) {
	int answer = 0;
	int width, height;
	width = getDiff(dots, 0);		// 0���� : x��
	height = getDiff(dots, 1);		// 1���� : y��

	return width * height;

	return answer;
	
}

int main() {

}