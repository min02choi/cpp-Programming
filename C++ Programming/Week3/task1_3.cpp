#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    string word = A;
    string temp;

    if (A.length() != B.length()) {     // ���̰� ���� ������ ���� �� ����
        return -1;
    }

    else {
        if (A.compare(B) == 0) {        // �ٷ� ���
            answer = 0;
        }
        else {
            for (int i = 0; i < A.length() - 1; i++) {
                temp = A.back();
                A.pop_back();
                A = temp + A;
                answer++;

                if (A.compare(B) == 0) {        // ������ break
                    return answer;
                    break;
                }

                else if (A.compare(B) != 0 && (i == A.length() - 2)) {
                    answer = -1;
                }
            }
        }
    }

    return answer;
}

int main() {

    string A = "asdf";
    string B = "dfas";

    cout << solution(A, B) << endl;

    return 0;

}