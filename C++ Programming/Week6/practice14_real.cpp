#include <iostream>
#include <string>

using namespace std;

string arr[105][105];

string add(string num1, string num2) {
    string num = "";
    int sum = 0;
    int size = max(num1.size(), num2.size());

    for (int i = 0; i < size || sum; i++) {
        if (num1.size() > i) sum += num1[i] - '0';
        if (num2.size() > i) sum += num2[i] - '0';

        num += sum % 10 + '0';
        sum /= 10;
    }

    return num;
}

string combi(int n, int m) {
    if (n == m || m == 0) return "1";

    string& ans = arr[n][m];

    if (ans != "") return ans;

    ans = add(combi(n - 1, m - 1), combi(n - 1, m));

    return ans;
}

long long int solution(int balls, int share) {
    int n = balls, m = share;
    long long int answer = 0;

    if (balls == share) {
        return 1;
    }

    combi(n, m);

    string word;        // 최종 결과가 string로 저장

    for (int i = arr[n][m].size() - 1; i >= 0; i--)
        word += arr[n][m][i];

    long long int k = 1;
    for (int i = word.size() - 1; i >= 0; i--) {
        answer += (word[i] - '0') * k;
        k *= 10;
    }

    return answer;
}

int main() {

    int balls = 50;
    int share = 8;

    cout << solution(balls, share) << endl;

    return 0;

}