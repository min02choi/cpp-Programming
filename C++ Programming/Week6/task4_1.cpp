#include <string>
#include <vector>
#include <iostream>

// �����׳��� ����Ͽ���
// ��, ������ x�� ����, ������ +�� ����

using namespace std;

// �� �̾��ֱ�
int connect_numbers(int num, int now) {
    num = num * 10 + now;
    return num;
}

string solution(string polynomial) {
    string answer = "";
    
    int temp = 0;       // �̹� ���ڰ� �ִ°�
    int now_temp = 0;   // ���� �ɸ� ����
    
    int x_cal = 0;      // x ���
    int x_flag = 0;
    int cal = 0;        // ����� ���
    int num_flag = 0;

    for (char s : polynomial) {

        if (s >= '0' && s <= '9') {     // �ϴ� �� ��ü
            now_temp = s - '0';
            temp = connect_numbers(temp, now_temp);
            // now_temp = 0;
        }
        else if (s == 'x') {
            x_flag = 1;

            if (temp == 0) {    
                temp++;
            }
        }
        else if (s == '+') {            // �� ����
            if (x_flag == 0) {          // ����� �߰�
                cal += temp;
                temp = 0;
            }
            else if (x_flag == 1) {     // x ��� �߰�
                x_cal += temp;
                x_flag = 0;
                temp = 0;
            }
        }
        now_temp = 0;
    }

    // temp�� ���� �����ִ� ���
    if (x_flag == 1) {
        x_cal += temp;
    }
    else if (x_flag == 0) {
        cal += temp;
    }

    // ��� �� answer�� ����
    // ������ �� 
        // 1. 0�� ��� ��� ���� ����
        // 2. x�� ����� 1�� ��� x���(1x -> X)
    // ������ ���������� ������ answer�� ����
    if (x_cal == 0 && cal != 0) {
        answer = to_string(cal);
    }
    else if (x_cal != 0 && cal == 0) {
        if (x_cal == 1) {
            answer = "x";
        }
        else {
            answer = to_string(x_cal) + "x";
        }
    }
    else if (x_cal == 0 && cal == 0) {
        answer = "0";
    }
    else {
        if (x_cal == 1) {       // ���� ó��
            answer = "x";
        }
        else {
            answer = to_string(x_cal) + "x";
        }

        answer = answer + " + " + to_string(cal);
    }
    
    return answer;
}

// ������ �ڵ�

// stoi �Լ� �ִµ� �׳� ������Ƽ� ¥�� ��
int my_stoi(string num) {
    int k = 1;
    int n = 0;

    for (int i = num.length() - 1; i >= 0; i--, k *= 10) {
        n += (num[i] - '0') * k;     // ?
    }
    return n;
}

// itos �Լ��� ���̺귯���� ����
string itos(int n) {
    string num = "";
    for (int i = n; i > 0; i /= 10) {
        char temp = (i % 10) + '0';
        num = temp + num;
    }
    return num;
}

// �߶� �־���
vector<string> tokenize(string letter) {
    vector<string> tokens;
    int i, j;
    for (int i = 0; i < letter.length(); i = j + 1) {
        for (j = i; j < letter.length(); j++) {
            if (letter[j] == ' ') {
                tokens.push_back(letter.substr(i, j - i));
                break;
            }
        }
    }
    return tokens;
}

string professor_solution(string polynimial) {
    string answer = "";
    int cof = 0;
    int constant = 0;
    vector<string> tokens = tokenize(polynimial);

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {

        }
        // tokens[i]�� string. �� ���� ������ ���ڰ� 'x'�ΰ�?
        else if (tokens[i][tokens[i].length() - 1] == 'x') {
            if (tokens[i].length() == 1) {
                cof++;
            }
            else {
                cof += my_stoi(tokens[i].substr(0, tokens[i].length() - 1));
            }
        }
        else {
            constant += my_stoi(tokens[i]);
        }
    }
    if (cof == 0) {
        answer = itos(constant);
    }
    else {
        if (cof == 1) {
            answer = "x + " + itos(constant);
        }
        else {
            answer = itos(cof) + "x";
        }
        if (constant > 0) {
            answer += " + " + itos(constant);
        }
    }
    return answer;
}

int main() {

    string polynomial = "3x + 7 + x";

    cout << solution(polynomial) << endl;
    cout << professor_solution(polynomial) << endl;     // �� �ȳ���

    return 0;
}