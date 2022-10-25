#include <iostream>
#include <string>
#include <stack>

// 일단 '('나오면 다 스택에다 집어넣고 ')'나오면 stack에서 pop시킴

using namespace std;

bool solution(string s) {
	stack<char> st;

	for (char c : s) {
		if (c == '(') {
			st.push(c);
		}
		else {
			if (!st.empty()) {
				st.pop();
			}
			else {
				return false;
			}
		}
		
	}
	return st.empty();
}

bool solutio2(string s) {
	int len = s.length();
	stack<char> st;

	for (int i = 0; i < len; i++) {
		char c = s[i];

		if (c == '(') {
			st.push(c);
		}
		else {
			if (!st.empty()) {
				st.pop();
			}
			else {
				return false;
			}
		}

	}
	return st.empty();
}

int main() {

}