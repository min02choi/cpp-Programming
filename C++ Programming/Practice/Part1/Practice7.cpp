#include <iostream>
#include <string>

// 65, 97:a

using namespace std;

string solution(string my_string) {
	string answer = "";
	char letter;

	for (char c : my_string) {
		if (c >= 'A' && c <= 'Z') {
			letter = c + 32;
		}
		else if (c >= 'a' && c <= 'z') {
			letter = c - 32;
		}
		answer = answer + letter;
	}
	return answer;
}

int main() {

	string word = "cccCCC";
	cout << solution(word) << endl;

	return 0;
}