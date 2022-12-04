#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<int> arr) {
	bool answer = false;
	
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == i + 1) {
			if (i == arr.size() - 1) {
				return true;
			}
		}
		else {
			return false;
		}
	}
	return false;
}

int main() {

	vector<int> arr = { 4, 1, 3, 2 };
	cout << solution(arr) << endl;

	return 0;
}