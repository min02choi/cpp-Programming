#include <string>
#include <vector>

// �𽺺�ȣ�� ���ĺ����� �ص��Ͽ���

using namespace std;

string which_alphabet(string word) {
    string s = "";

    if (word == ".-") {
        s = "a";
    }
    else if (word == "-...") {
        s = "b";
    }
    else if (word == "-.-.") {
        s = "c";
    }
    else if (word == "-..") {
        s = "d";
    }
    else if (word == ".") {
        s = "e";
    }
    else if (word == "..-.") {
        s = "f";
    }
    else if (word == "--.") {
        s = "g";
    }
    else if (word == "....") {
        s = "h";
    }
    else if (word == "..") {
        s = "i";
    }
    else if (word == ".---") {
        s = "j";
    }
    else if (word == "-.-") {
        s = "k";
    }
    else if (word == ".-..") {
        s = "l";
    }
    else if (word == "--") {
        s = "m";
    }
    else if (word == "-.") {
        s = "n";
    }
    else if (word == "---") {
        s = "o";
    }
    else if (word == ".--.") {
        s = "p";
    }
    else if (word == "--.-") {
        s = "q";
    }
    else if (word == ".-.") {
        s = "r";
    }
    else if (word == "...") {
        s = "s";
    }
    else if (word == "-") {
        s = "t";
    }
    else if (word == "..-") {
        s = "u";
    }
    else if (word == "...-") {
        s = "v";
    }
    else if (word == ".--") {
        s = "w";
    }
    else if (word == "-..-") {
        s = "x";
    }
    else if (word == "-.--") {
        s = "y";
    }
    else if (word == "--..") {
        s = "z";
    }

    return s;

}

string solution(string letter) {
    string answer = "";
    string temp = "";

    for (char s : letter) {

        if (s == ' ') {     // �ǵ�
            answer = answer + which_alphabet(temp);
            temp = "";
        }
        else {              // ������ ��� -> �߰�
            temp += s;
        }
    }

    answer = answer + which_alphabet(temp);

    return answer;
}

int main() {

    string morse = "";

    cout << solution(morse) << endl;

    return 0;
}