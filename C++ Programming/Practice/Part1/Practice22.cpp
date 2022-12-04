#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
	vector<int> answer;
	int dnum = (denum1 * num2) + (denum2 * num1);
	int num = num1 * num2;							

	int min = dnum;
	if (min > num) {
		min = num;
	}

	int i = 2;
	while (i <= min) {
		if (dnum % i == 0 && num % i == 0) {
			dnum /= i;
			num /= i;
		}
		else {
			i++;
		}
	}
	answer.push_back(dnum);
	answer.push_back(num);

	return answer;
}

int main() {
	solution(1, 2, 3, 4);
}