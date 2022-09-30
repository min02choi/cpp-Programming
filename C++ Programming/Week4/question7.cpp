#include <string>
#include <vector>
#include <stdio.h>

// 대문자, 소문자로 이루어진 문자를 입력받아 대문자는 소문자로, 소문자는 대문자로 출력하기
// 왜이러지 푸는데 3141592년걸림;

// 공부하세요


using namespace std;

// Tlq 왜 안됨
string solution1(string my_string) {
    string answer = "";
    char w;

    for (int i = 0; my_string.length(); i++) {

        if (my_string[i] >= 65 && my_string[i] <= 90) {
            w = my_string[i] + 32;
        }

        else {
            w = my_string[i] - 32;
        }

        answer.push_back(w);

    }

    return answer;
}


char change(char c) {
    if (c > 'Z') {
        return c - ('a' - 'A');
    }
    else {
        return c + ('a' - 'A');
    }
}

string solution(string my_string) {
    string answer = "";
    char a;

    for (int i = 0; i < my_string.length(); i++) {
        a = my_string.at(i);
        a = change(a);
        answer.push_back(a);
    }

    return answer;
}



int main() {
    string word = "cccCCC";
    solution(word);
    solution1(word);

    return 0;
}