#include <string>
#include <vector>
#include <iostream>

/*
    my_string ���� �ڿ����� ���� ���Ͻÿ�.
    ����Ǵ� ���ڴ� �ϳ��� ���ڷ� ��.
*/

using namespace std;

// �� Ǯ��
int solution(string my_string) {
    int answer = 0;

    vector<int> num_list;
    string num = "";

    for (int i = 0; i < my_string.length(); i++) {

        if (my_string[i] >= '0' && my_string[i] <= '9') {
            num += my_string[i];    // string + char ����
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

// ������ Ǯ��
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

        if (my_string[i] < '0' || my_string[i] > '9') {     // ���ĺ��� ���
            if (temp.size() > 0) {
                numbers.push_back(changeToDec(temp));
                temp.clear();
            }
        }
        else {                                              // ������ ���
            temp.push_back(my_string[i] - '0');     // �ƽ�Ű �ڵ� ���� �ƴ� ��¥ ���ڸ� �ְ� ���� ��
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