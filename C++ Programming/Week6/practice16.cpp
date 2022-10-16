#include <string>
#include <vector>
#include <iostream>

// 자연수 n이 매개변수로 주어질 때 두 숫자의 곱이 n인 자연수 순서쌍의 개수를 구하시오

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i < n + 1; i++) {
        if (n % i == 0) {
            answer++;
        }
    }

    return answer;
}

int main() {
    int n = 72;

    cout << solution(n) << endl;

    return 0;
}