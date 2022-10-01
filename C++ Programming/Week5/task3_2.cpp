#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string) {
    int answer = 0;

    vector<int> num_list;
    string num = "";

    for (int i = 0; i < my_string.length(); i++) {

        if (my_string[i] >= '0' && my_string[i] <= '9') {
            num += my_string[i];    // string + char °¡´É
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

int main() {

    string word = "aAb1B2cC34oOp";
    cout << solution(word) << endl;

    return 0;
}