#include <string>
#include <vector>
#include <iostream>
#include <sstream>


/*
    끝말잇기 게임
*/

using namespace std;

bool solution(string s) {
    int i = 0;      // 한 칸씩 진전
    int k = 0;
    bool b = false;

    while (k <= s.length() || k == 0) {

        if (s[i] == '(' && s.length() >= 2) {
            if (s[i + 1] == ')') {
                s.replace(i, 2, "");
                i = 0;
                continue;
            }
            else {
                i++;
            }
        }
        else if (s.length() == 0) {
            return true;
        }
        else if (s[i] == ')' && s.length() >= 2) {
            i++;
        }
        k++;

    }

    if (s.length() == 0) {
        return true;
    }
    return false;

}

int main() {
    solution("(())()");
}