#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {

    vector<int> start = { 0, 0 };
    vector<int> answer;
    
    int max_width = board[0] / 2;  // 최대 이동 가능
    int max_height = board[1] / 2;

    int min_width = -(board[0] / 2);  // 최대 이동 가능
    int min_height = -(board[1] / 2);

    for (string s : keyinput) {

        if (s == "left") {
            // if (max_width >= start[0] + 1 && min_width <= start[0] - 1)
            if (min_width <= start[0] - 1) {    // 이동 가능
                start[0]--;
            }
        }
        else if (s == "right") {
            if (max_width >= start[0] + 1) {    // 이동 가능
                start[0]++;
            }
        }
        else if (s == "up") {
            if (max_height >= start[1] + 1) {    // 이동 가능
                start[1]++;
            }
        }
        else if (s == "down") {
            if (min_height <= start[1] - 1) {    // 이동 가능
                start[1]--;
            }
        }
    }

    // return answer;
    return start;
}

int main() {
    vector<string> keyinput = { "down", "down", "down", "down", "down" };
    vector<int> board = { 7, 9 };

    board = solution(keyinput, board);

    for (int i : board) {
        cout << i << endl;
    }

    return 0;
}