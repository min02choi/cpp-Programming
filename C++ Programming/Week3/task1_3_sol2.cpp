#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    vector<char> word1;
    vector<char> word2;

    if (A.length() != B.length()) {     // 길이가 다르면 바로 탈락
        return -1;
    }

    for (int i = 0; i < A.length(); i++) {
        word1.push_back(A[i]);
        word2.push_back(B[i]);
    }

    for (int i = 0; i < A.length(); i++) {

        char temp = word1.back();
        word1.insert(word1.begin(), temp);
        word1.pop_back();
        answer++;

        if (word1 == word2) {
            return answer;
        }            
    }

    answer = -1;

    return answer;
}

int main() {

    string A = "asdf";
    string B = "dfas";

    cout << solution(A, B) << endl;

    return 0;

}