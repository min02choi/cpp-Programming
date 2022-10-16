#include <string>
#include <vector>
#include <iostream>

// 동류항끼리 계산하여라
// 단, 변수는 x만 존재, 연산은 +만 존재

using namespace std;

// 수 이어주기
int connect_numbers(int num, int now) {
    num = num * 10 + now;
    return num;
}

string solution(string polynomial) {
    string answer = "";
    
    int temp = 0;       // 이미 숫자가 있는가
    int now_temp = 0;   // 현재 걸린 숫자
    
    int x_cal = 0;      // x 계수
    int x_flag = 0;
    int cal = 0;        // 상수항 계수
    int num_flag = 0;

    for (char s : polynomial) {

        if (s >= '0' && s <= '9') {     // 일단 수 합체
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
        else if (s == '+') {            // 총 정산
            if (x_flag == 0) {          // 상수항 추가
                cal += temp;
                temp = 0;
            }
            else if (x_flag == 1) {     // x 계수 추가
                x_cal += temp;
                x_flag = 0;
                temp = 0;
            }
        }
        now_temp = 0;
    }

    // temp에 수가 남아있는 경우
    if (x_flag == 1) {
        x_cal += temp;
    }
    else if (x_flag == 0) {
        cal += temp;
    }

    // 출력 값 answer에 저장
    // 주의할 점 
        // 1. 0인 경우 출력 하지 말것
        // 2. x의 계수가 1인 경우 x출력(1x -> X)
    // 조건을 여러가지로 나누어 answer에 저장
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
        if (x_cal == 1) {       // 따로 처리
            answer = "x";
        }
        else {
            answer = to_string(x_cal) + "x";
        }

        answer = answer + " + " + to_string(cal);
    }
    
    return answer;
}

// 교수님 코드

// stoi 함수 있는데 그냥 연습삼아서 짜본 것
int my_stoi(string num) {
    int k = 1;
    int n = 0;

    for (int i = num.length() - 1; i >= 0; i--, k *= 10) {
        n += (num[i] - '0') * k;     // ?
    }
    return n;
}

// itos 함수도 라이브러리에 있음
string itos(int n) {
    string num = "";
    for (int i = n; i > 0; i /= 10) {
        char temp = (i % 10) + '0';
        num = temp + num;
    }
    return num;
}

// 잘라서 넣어줌
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
        // tokens[i]는 string. 이 값의 마지막 글자가 'x'인가?
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
    cout << professor_solution(polynomial) << endl;     // 잘 안나옴

    return 0;
}