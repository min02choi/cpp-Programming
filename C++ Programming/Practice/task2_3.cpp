#include <iostream>
#include <string>
#include <vector>

// 문제 : 두 개의 string 형태의 이진수를 계산하여 결과를 string 형태로 반환하라

using namespace std;

string solution(string a, string b) {
	string answer = "";
	vector<int> total;
	int ans = 0;
	int n1, n2, carry = 0;
	int temp = 0;

	int num1 = stoi(a);
	int num2 = stoi(b);
	int i = 1;

	while (num1 != 0 && num2 != 0 && carry != 0) {
		n1 = num1 % 10;
		n2 = num2 % 10;

		temp = n1 + n2 + carry;

		if (temp >= 2) {		// carry 발생
			carry = temp / 2;
			temp = temp % 2;
		}
		total.push_back(temp);

		num1 /= 10;
		num2 /= 10;

	}

	for (int i : total) {
		string temp = to_string(i);
		answer = a + answer;
		
	}
	
	return answer;
}

int main() {

}
