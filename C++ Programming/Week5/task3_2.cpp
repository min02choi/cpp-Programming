#include <string>
#include <vector>
#include <iostream>

/*
    my_string 안의 자연수의 합을 구하시오.
    연결되는 숫자는 하나의 숫자로 봄.
*/

using namespace std;

// 내 풀이
int solution(string my_string) {
    int answer = 0;

    vector<int> num_list;
    string num = "";

    for (int i = 0; i < my_string.length(); i++) {

        if (my_string[i] >= '0' && my_string[i] <= '9') {
            num += my_string[i];    // string + char 가능
        }

        else if ((my_string[i] < '0' || my_string[i] > '9') && num != "") {
            num_list.push_back(stoi(num));
            num = "";
        }
    }

    if (num != "") {
        num_list.push_back(stoi(num));
    }

    for (int i : num_list) {
        answer += i;
    }

    return answer;
}

// 교수님 풀이
int changeToDec(vector<int> temp) {
    int k = 1;
    int num = 0;

    for (int i = temp.size() - 1; i >= 0; i--, k *= 10) {
        num += temp[i] * k;
    }
    return num;
}

vector<int> getNumbers(string my_string) {
    vector<int> numbers;
    vector<int> temp;

    for (int i = 0; i < my_string.length(); i++) {

        if (my_string[i] < '0' || my_string[i] > '9') {     // 알파벳인 경우
            if (temp.size() > 0) {
                numbers.push_back(changeToDec(temp));
                temp.clear();
            }
        }
        else {                                              // 숫자인 경우
            temp.push_back(my_string[i] - '0');     // 아스키 코드 값이 아닌 진짜 숫자를 넣고 싶을 때
        }        
    
    }

    if (temp.size() > 0) {
        numbers.push_back(changeToDec(temp));
    }
    return numbers;
}

int professor_solution(string my_string) {
    int answer = 0;
    vector<int> numbers = getNumbers(my_string);

    for (int i = 0; i < numbers.size(); i++) {
        answer += numbers[i];
    }

    return answer;
}



int main() {

    string word = "aAb1B2cC34oOp";
    
    cout << "my solution : " << solution(word) << endl;
    cout << "professor solution : " << professor_solution(word) << endl;

    return 0;
}