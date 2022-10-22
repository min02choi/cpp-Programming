#include <string>
#include <vector>
#include <iostream>

/*
    �����ձ� ����
*/

using namespace std;

// 2�ڸ� �̻��� �ܾ����� �˻�
int is_word(string word) {
    if (word.length() >= 2) {
        return 0;
    }
    return 1;
}

// �ߺ��� �ܾ����� �˻�
int is_duplicated(string word, vector<string> duplicated) {
    for (int i = 0; i < duplicated.size(); i++) {
        if (word == duplicated[i]) {
            return 1;
        }
    }
    return 0;
}

// ����� �ܾ����� �˻�
int is_connected(string cur_word, string bef_word) {
    if (bef_word[bef_word.length() - 1] == cur_word[0]) {
        return 0;
    }
    return 1;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> duplicated;

    string cur_word = "", bef_word = "";
    
    int player, turn = 0;
    // int game_flag = 0;
    int end_flag = 0;

    int i = 0;
    for (i = 0; i < words.size(); i++) {
        
        bef_word = cur_word;
        cur_word = words[i];
        
        /*
        game_flag = is_word(cur_word);
        if (game_flag == 1) {
            break;
        }

        game_flag = is_duplicated(cur_word, duplicated);
        if (game_flag == 1) {
            break;
        }
        */

        if (is_word(cur_word) || is_duplicated(cur_word, duplicated)) {
            break;
        }

        if (bef_word != "") {
            /*
            game_flag = is_connected(cur_word, bef_word);
            if (game_flag == 1) {
                break;
            }
            */
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
    vector<string> words = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };
    
    vector<int> answer = solution(player, words);

    cout << answer[0] << " " << answer[1] << endl;

    return 0;
}