#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(int n) {
	int answer = 0;
	string num = to_string(n);

	for (int i = 0; i < num.length(); i++) {
		char k = num[i] - '0';
		answer += k;
	}
	return answer;
}

int main() {
	int n = 987;
	cout << solution(n) << endl;

	return 0;
}