#include <iostream>
#include <string>
#include <vector>

// 문제 : 두 개의 string 형태의 이진수를 계산하여 결과를 string 형태로 반환하라

using namespace std;

/*
// 문자열 이진수를 숫자로 변환 : stoi()
int string_to_int(string str_num, int size) {
    int int_num = 0;

    for (int i = 0; i < size; i++) {
        if (i != 0) {
            int_num *= 10;
        }

        if (str_num[i] == '1') {
            int_num += 1;
        }
    }
    return int_num;
}
*/

string solution(string bin1, string bin2) {
    string answer = "";
    
    int num1, num2;
    int temp1, temp2, result;
    int over = 0;

    vector<int> total;

    // int로의 전환
    // 난 함수를 직접 구현했는데 stoi라는 함수가 있었음ㅋㅋ
    // num1 = string_to_int(bin1, bin1.length());
    // num2 = string_to_int(bin2, bin2.length());

    num1 = stoi(bin1);
    num2 = stoi(bin2);

    while (true) {

        if (num1 == 0 && num2 == 0 && over == 0) {
            break;
        }

        temp1 = num1 % 10;
        temp2 = num2 % 10;

        result = temp1 + temp2 + over;

        num1 /= 10;
        num2 /= 10;

        if (result >= 2) {
            over = 1;
            result -= 2;        // 더하는 수가 두개 보장이므로 할 수 있는 코드
        }
        else {
            over = 0;
        }

        total.push_back(result);
    }

    string a;

    for (int i : total) {
        a = to_string(i);
        answer = a + answer;
    }

    return answer;
}

// 교수님 코드
int getDigit(string bin, int i) {
    if (bin.length() > i) {
        return bin[bin.length() - i - 1] - '0';
    }
    else {
        return 0;
    }
}

string makeAnswer(string ans, int i) {
    if (i == 1) {
        return "1" + ans;
    }
    else {
        return "0" + ans;
    }
}

string solution_professor(string bin1, string bin2) {

    string answer = "";
    int a, b, c, s;
    c = 0;
    int len = bin1.length();

    if (len < bin2.length()) {
        len = bin2.length();
    }

    for (int i = 0; i < len; i++) {
        a = getDigit(bin1, i);
        b = getDigit(bin2, i);
        s = (a + b + c) % 2;
        c = (a + b + c) / 2;
        answer = makeAnswer(answer, s);
    }

    if (c == 1) {
        answer = makeAnswer(answer, c);
        return answer;
    }

}


int main() {

    string a = "101";
    string b = "1";

    cout << solution(a, b) << endl;
    cout << solution_professor(a, b) << endl;

    return 0;
}