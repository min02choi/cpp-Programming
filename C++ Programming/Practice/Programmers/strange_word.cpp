#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 올바른 문자로 반환
string correct_word(int idx, char c) {
	char new_char;

	if (idx % 2 == 0 && (c >= 'a' || c >= 'z')) {
		new_char = c - 23;
	}
	else if (idx % 2 == 1 && (c >= 'A' || c >= 'Z')) {
		new_char = c + 23;
	}

	return to_string(new_char);
}

string solution(string s) {
	int word_flag = 0;
	int word_cnt = 0;
	int word_len = 0;
	string answer = "";
	string sub_word = "";

	for (int i = 0; i < s.length(); i++) {

		if (s[i] != ' ' && s[i - 1] ) {
			sub_word += s[i];
			solution(sub_word);
		}
		else if (s[i] == ' ') {

		}
	}

}



int main() {
	
}