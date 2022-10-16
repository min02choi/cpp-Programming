#include <string>
#include <vector>
#include <iostream>

/*
	점 4개를 입력받고 해당 사각형의 넓이를 구하라
	(단, 직사각형의 모양이 아닌 좌표는 입력되지 않는다.)
*/


using namespace std;

// 교수님 풀이
int getDiff(vector<vector<int>> dots, int dim) {
	int max, min;
	max = -256;		// 절대 될 수 없는 값
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
	width = getDiff(dots, 0);		// 0차원 : x축
	height = getDiff(dots, 1);		// 1차원 : y축

	return width * height;

	return answer;
	
}

int main() {

}