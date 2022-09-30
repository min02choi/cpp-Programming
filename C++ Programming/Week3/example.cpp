#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	vector<string> words;
	for (string s; cin >> s && s != "quit"; ) {
		words.push_back(s);
	}

	sort(words.begin(), words.end());

	// 规过 1
	cout << "Solution 1" << endl;
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << endl;
	}

	// 规过 2
	cout << "Solution 2" << endl;
	for (string s : words) {
		cout << s << endl;
	}

}