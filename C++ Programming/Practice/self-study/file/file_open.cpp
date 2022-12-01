#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout;
	fout.open("./a.txt");

	for (int i = 0; i <= 10; i++) {
		fout << i << endl;
	}
	fout << endl;

	fout.close();

	return 0;
}