#include <string>
#include <vector>
#include <iostream>

/*
    다음 조건을 만족하는 가장 큰 정수 i를 return 하시오.
    i! ≤ n
*/


using namespace std;

// 내 풀이
int solution(int n) {
    int answer = 0;
    int result = 1;

    for (int i = 1; ; i++) {
        result *= i;
        if (result > n) {
            answer = i - 1;
            break;
        }
    }

    return answer;
}

/*
// 교수님 풀이
// 효율성을 위해 함수 별도로 사용하지 말 것
int cal(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= i;
    }
    return ans;
}

int professor_solution(int n) {
    int answer = 0;
    int temp = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
        if (cal(i) < n) {
            
        }
    }

    return answer;
}
*/


int main() {

    int n = 3628800;

    cout << solution(n) << endl;

    return 0;
}