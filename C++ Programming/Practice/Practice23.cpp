#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// to_string() ¿Ã ¿÷¿Ω
string int_to_string(int num) {
	return "";
}

int solution(int n, int m) {
	int answer = 0;
	
	string str_num;
	int str_len = 0;
	int half;

	for (int i = n; i <= m; i++) {
		str_num = to_string(i);
		str_len = str_num.length();
		half = str_len / 2;

		for (int j = 0; j <= half; j++) {
			if (str_num[j] != str_num[str_len - j - 1]) {
				break;
			}
			if (j == half) {
				answer++;
			}
		}
	}

	return answer;
}

int main() {
	
	cout << solution(100, 300) << endl;

	return 0;
}