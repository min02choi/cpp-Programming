#include <iostream>
#include <vector>
#include <string>

using namespace std;

void multify_seven_times(int &a, double &b) {
	a *= 7;
	b *= 7;
}

void change_vector_int(vector<string>& words, int& num) {
	words.push_back("Hello");
	num += 1;
}

void print_vector(vector<string> words) {
	for (string s : words) {
		cout << s << " ";
	}
	cout << endl;
}


int main() {
	int a = 7;
	double b = 1.2;
	vector<string> w = { "Choi Min Young" };

	multify_seven_times(a, b);
	cout << a << " " << b << endl;

	change_vector_int(w, a);
	print_vector(w);
	cout << a << endl;

	return 0;
}