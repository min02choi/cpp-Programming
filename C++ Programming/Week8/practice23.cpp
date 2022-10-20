#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n, int m) {
    int answer = 0;

    for (int i = n; i <= m; i++) {
        string number = to_string(i);
        
        int half = number.length() / 2;
        
        // 0인 경우 아래의 for문에 들어가지 않으므로
        if (half == 0) {
            answer++;
        }

        for (int i = 0; i <= half; i++) {

            if (number[i] != number[number.length() - (i + 1)]) {
                break;
            }
            if (i == half - 1) {
                answer++;
            }
        }
    }

    return answer;
}


// 아스키 코드 값!!!
void getStr(string& str, int k) {
    str = "";
    for (int i = k; i > 0; i /= 10) {
        str = (char)(('0' + (i % 10))) + str;
    }
}

void getRevStr(string& str, int k) {
    str = "";
    for (int i = k; i > 0; i /= 10) {
        str = str + (char)(('0' + (i % 10)));
    }
}

bool isPal(int k) {
    string str, revstr;
    getStr(str, k);
    getRevStr(revstr, k);
    if (str == revstr) {
        return true;
    }
    else {
        return false;
    }
}

int professor_solution(int n, int m) {
    int answer = 0;

    for (int i = n; i <= m; i++) {
        if (isPal(i)) {
            answer++;
        }
    }
    return answer;
}

int main() {
    solution(1, 18);

    return 0;
}