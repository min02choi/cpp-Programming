#include <string>
#include <vector>
#include <iostream>

// 모스부호를 알파벳으로 해독하여라

using namespace std;

string which_alphabet(string word) {
    string s = "";

    if (word == ".-")           { s = "a"; }
    else if (word == "-...")    { s = "b"; }
    else if (word == "-.-.")    { s = "c"; }
    else if (word == "-..")     { s = "d"; }
    else if (word == ".")       { s = "e"; }
    else if (word == "..-.")    { s = "f"; }
    else if (word == "--.")     { s = "g"; }
    else if (word == "....")    { s = "h"; }
    else if (word == "..")      { s = "i"; }
    else if (word == ".---")    { s = "j"; }
    else if (word == "-.-")     { s = "k"; }
    else if (word == ".-..")    { s = "l"; }
    else if (word == "--")      { s = "m"; }
    else if (word == "-.")      { s = "n"; }
    else if (word == "---")     { s = "o"; }
    else if (word == ".--.")    { s = "p"; }
    else if (word == "--.-")    { s = "q"; }
    else if (word == ".-.")     { s = "r"; }
    else if (word == "...")     { s = "s"; }
    else if (word == "-")       { s = "t"; }
    else if (word == "..-")     { s = "u"; }
    else if (word == "...-")    { s = "v"; }
    else if (word == ".--")     { s = "w"; }
    else if (word == "-..-")    { s = "x"; }
    else if (word == "-.--")    { s = "y"; }
    else if (word == "--..")    { s = "z"; }

    return s;

}

string solution(string letter) {
    string answer = "";
    string temp = "";

    for (char s : letter) {

        if (s == ' ') {     // 판독
            answer = answer + which_alphabet(temp);
            temp = "";
        }
        else {              // 문자일 경우 -> 이전 문자에 추가
            temp += s;
        }
    }

    answer = answer + which_alphabet(temp);

    return answer;
}

// 교수님 풀이
// class notFound { };

char translate(string sub) {

    vector<string> dic = { ".-", "-...", "-.-.", "-..", ".","..-.", "--.",
                          "....", "..", ".---", "-.-", ".-..", "--", "-.",
                          "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                          "...-", ".--", "-..-", "-.--", "--.." };

    for (int i = 0; i < dic.size(); i++) {
        if (sub == dic[i]) {
            return 'a' + i;
        }
        // throw notFound();
    }
}

string professor_solution(string letter) {
    string answer = "";
    int i, j;

    // 만약 딜리미터(구분자)가 없다면 for문 두번 돌림
    for (i = 0; i < letter.length(); i = j + 1) {
        for (j = i; j < letter.length(); j++) {
            if (letter[j] == ' ') {
                answer += translate(letter.substr(i, j - i));
                i = j + 1;
                break;
            }
            if (j == letter.length()) {
                answer += translate(letter.substr(i, j - i + 1));

            }
        }
    }
    return answer;
}


int main() {

    string morse = ".-.";

    cout << solution(morse) << endl;
    cout << professor_solution(morse) << endl;      // 미완

    return 0;
}