#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

// 함수 다시 한번 볼 것

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;

	while (n != 1) {
		for (int i = 2; i <= n; i++) {
			if (n % i == 0) {
				n /= i;
				answer.push_back(i);
				break;
			}
		}
	}

	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

int main() {

	//소인수분해
	int n;
	cin >> n;

	cout << solution(n) << endl;

	return 0;
}