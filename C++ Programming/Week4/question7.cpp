#include <string>
#include <vector>
#include <stdio.h>

// �빮��, �ҹ��ڷ� �̷���� ���ڸ� �Է¹޾� �빮�ڴ� �ҹ��ڷ�, �ҹ��ڴ� �빮�ڷ� ����ϱ�
// ���̷��� Ǫ�µ� 3141592��ɸ�;

// �����ϼ���


using namespace std;

// Tlq �� �ȵ�
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