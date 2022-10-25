#include <iostream>
#include <string>
#include <stack>

// �ϴ� '('������ �� ���ÿ��� ����ְ� ')'������ stack���� pop��Ŵ

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