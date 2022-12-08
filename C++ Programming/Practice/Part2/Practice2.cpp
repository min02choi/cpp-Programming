#include <iostream>
#include <string>
#include <vector>

// status: 200


using namespace std;

class Wallet {
	vector<vector<int>> wallet;
	void sizeModify();
	int getMaxWidth();
	int getMaxHeight();
public:
	Wallet(vector<vector<int>> w);
	int solution();
};

Wallet::Wallet(vector<vector<int>> w) {
	wallet = w;
}

int Wallet::solution() {
	int walSize;
	sizeModify();
	walSize = getMaxWidth() * getMaxHeight();

	return walSize;
}

void Wallet::sizeModify() {
	int temp = 0;
	for (int i = 0; i < wallet.size(); i++) {
		if (wallet[i][0] > wallet[i][1]) {
			temp = wallet[i][1];
			wallet[i][1] = wallet[i][0];
			wallet[i][0] = temp;
		}
	}
}

int Wallet::getMaxWidth() {
	int max = wallet[0][0];
	for (int i = 0; i < wallet.size(); i++) {
		if (max < wallet[i][0]) {
			max = wallet[i][0];
		}
	}
	return max;
}

int Wallet::getMaxHeight() {
	int max = wallet[0][1];
	for (int i = 0; i < wallet.size(); i++) {
		if (max < wallet[i][1]) {
			max = wallet[i][1];
		}
	}
	return max;
}


int main() {

	vector<vector<int>> vec = { {60, 50}, {30, 70}, {60, 30}, {80, 40} };
	vector<vector<int>> vec2 = { {10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15} };
	Wallet w(vec2);

	cout << w.solution() << endl;

	return 0;
}