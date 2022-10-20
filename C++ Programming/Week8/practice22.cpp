#include <string>
#include <vector>
#include <iostream>

// 시험문제와 매우 유사

using namespace std;

vector<int> solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;

    int top = denum1 * num2 + denum2 * num1;
    int bot = num1 * num2;

    int min = top;
    if (bot < min) {
        min = bot;
    }

    int i = 2;
    while (i <= min) {
        if (top % i == 0 && bot % i == 0) {
            top = top / i;
            bot = bot / i;
        }
        else {
            i++;
        }

    }

    answer.push_back(top);
    answer.push_back(bot);

    return answer;
}

// 리턴해야 하는 값이 두개이므로 call by refrence 로 처리
void getSum(int& denum, int& num, int denum1, int num1, int denum2, int num2) {
    num = num1 * num2;
    denum = denum1 * num2 + denum2 * num1;
}

void postDiv(int& denum, int& num) {
    for (int i = 2; denum > 1 && num > 1 && denum >= i && num >= i;) {
        
        // i가 공약수인가
        // i가 for문에 들어가지 않은 이유: i가 공약수인 경우 i로 retry를 해주기 위해서 i의 값을 변경시키지 않음
        if (denum % i == 0 && num % i == 0) {
            denum = denum / i;
            num = num / i;
        }

        // 안 나눠지는 경우 i를 증가하여 나눔
        else {
            i++;
        }
    }
}

vector<int> professor_solution(int denum1, int num1, int denum2, int num2) {
    vector<int> answer;

    int denum, num;

    getSum(denum, num, denum1, num1, denum2, num2);
    postDiv(denum, num);
    answer.push_back(denum);
    answer.push_back(num);

    return answer;
}

int main() {
    //cout << solution(1, 2, 3, 4) << endl;

    solution(1, 2, 3, 4);

    return 0;
}