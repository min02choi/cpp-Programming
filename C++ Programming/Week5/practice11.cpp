#include <string>
#include <vector>
#include <iostream>

/*
    ���� ������ �����ϴ� ���� ū ���� i�� return �Ͻÿ�.
    i! �� n
*/


using namespace std;

// �� Ǯ��
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
// ������ Ǯ��
// ȿ������ ���� �Լ� ������ ������� �� ��
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