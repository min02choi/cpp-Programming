#include <string>
#include <vector>
#include <iostream>

/*
    끝말잇기 게임을 try-catch으로 구현
*/

class lengthNotQulified { };
class wordDuplicated { };
class wordNotConnected { };


using namespace std;

// 2자리 이상의 단어인지 검사
int is_word(string word) {
    if (word.length() >= 2) {
        return 0;
    }
    throw lengthNotQulified();
}

// 중복된 단어인지 검사
int is_duplicated(string word, vector<string> duplicated) {
    for (int i = 0; i < duplicated.size(); i++) {
        if (word == duplicated[i]) {
            throw wordDuplicated();
        }
    }
    return 0;
}

// 연결된 단어인지 검사
int is_connected(string cur_word, string bef_word) {
    if (bef_word[bef_word.length() - 1] == cur_word[0]) {
        return 0;
    }
    throw wordNotConnected();
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> duplicated;

    string cur_word = "", bef_word = "";

    int player, turn = 0;
    int end_flag = 0;
    int i = 0;

    try {
        for (i = 0; i < words.size(); i++) {

            bef_word = cur_word;
            cur_word = words[i];

            if (is_word(cur_word) || is_duplicated(cur_word, duplicated)) {
                break;
            }

            if (bef_word != "") {
                if (is_connected(cur_word, bef_word)) {
                    break;
                }
            }

            if (i == words.size() - 1) {
                end_flag = 1;
                break;
            }

            duplicated.push_back(cur_word);
        }
    }
    catch (lengthNotQulified e) {
        cout << "lengthNotQulified Error" << endl;
        answer.push_back(-1);
        return answer;
    }
    catch (wordDuplicated e) {
        cout << "wordDuplicated Error" << endl;
        answer.push_back(-2);
        return answer;
    }
    catch (wordNotConnected e) {
        cout << "wordNotConnected Error" << endl;
        answer.push_back(-3);
        return answer;
    }

    if (end_flag == 0) {
        turn = i / n + 1;

        player = (i + 1) % n;
        if (player == 0) {
            player = n;
        }
    }
    else if (end_flag == 1) {
        turn = 0;
        player = 0;
    }

    answer.push_back(player);
    answer.push_back(turn);

    return answer;
}

int main() {

    int player = 3;
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "ttank" };

    vector<int> answer = solution(player, words);

    // cout << answer[0] << " " << answer[1] << endl;
    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}