#include <string>
#include <vector>
#include <iostream>

// �ڿ��� n�� �Ű������� �־��� �� �� ������ ���� n�� �ڿ��� �������� ������ ���Ͻÿ�

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