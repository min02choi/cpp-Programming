#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	ifstream fout;
	fout.open("./Practice/self-study/file/a.txt");
	vector<string> v;
	for (int i = 0; i <= 10; i++) {
		string s;
		fout >> s;
		v.push_back(s);
	}
	for (auto s : v)
		cout << s << endl;
	fout.close();

	return 0;
}