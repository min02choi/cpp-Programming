#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPalendrom(string n) {
	stack<char> st;

	for (char c : n) {
		if (!st.empty()) {
			if (st.top() == c) {
				st.pop();
			}
			else {
				st.push(c);
			}
		}
	}
	return st.empty();
}

int solution(int n, int m) {
	int answer = 0;
	string word;

	for (int i = n; i <= m; i++) {
		word = to_string(i);
		if (isPalendrom(word) == true) {
			answer++;
		}

	}
	return answer;

}

int main() {

}