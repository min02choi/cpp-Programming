#include <string>
#include <vector>
#include <algorithm>

// 최빈값 구하기
// 하..

using namespace std;

void store_numbers(int *how_many[1000], const vector<int> array) {
	for (int i = 0; i < array.size(); i++) {
		how_many[array[i]]++;
	}
}

int solution(vector<int> array) {

	int answer = 0;
	int how_many[1000] = { 0, };

	for (int i = 0; i < array.size(); i++) {
		how_many[array[i]]++;
	}

	int max_num;
	int max_cnt = -1;
	int flag = 0;

	for (int i = 0; i < 1000; i++) {
		if (how_many[i] > max_cnt) {
			max_num = i;
			max_cnt = how_many[i];
			flag = 0;
		}
		else if (how_many[i] == max_cnt) {
			flag++;
		}
	}
	if (flag >= 1) {
		answer = -1;
	}
	else {
		answer = max_num;
	}

	return answer;
}

int main() {

}