#include <iostream>

using namespace std;

int main() {
	
	int a, b;

	try {
		cin >> a >> b;

		if (b <= 0) {
			throw b;
		}
		cout << a / b << endl;

	}
	catch (int expn) {
		cout << "Error! Can't divide by " << expn << endl;
	}

	cout << "program end" << endl;

	return 0;
}