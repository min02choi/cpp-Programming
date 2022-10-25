#include <iostream>
#include <string>
#include <vector>

// ���� : �� ���� string ������ �������� ����Ͽ� ����� string ���·� ��ȯ�϶�

using namespace std;

/*
// ���ڿ� �������� ���ڷ� ��ȯ : stoi()
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

    // int���� ��ȯ
    // �� �Լ��� ���� �����ߴµ� stoi��� �Լ��� �־�������
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
            result -= 2;        // ���ϴ� ���� �ΰ� �����̹Ƿ� �� �� �ִ� �ڵ�
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

// ������ �ڵ�
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