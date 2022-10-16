#include <string>
#include <vector>
#include <iostream>


using namespace std;

// �� Ǯ��
vector<int> solution(vector<string> keyinput, vector<int> board) {

    vector<int> start = { 0, 0 };
    vector<int> answer;
    
    int max_width = board[0] / 2;  // �ִ� �̵� ���� ��ǥ��
    int max_height = board[1] / 2;

    int min_width = -(board[0] / 2);  // �ּ� �̵� ���� ��ǥ��
    int min_height = -(board[1] / 2);

    for (string s : keyinput) {

        if (s == "left") {
            if (min_width <= start[0] - 1) {    // �̵� ���� ��ǥ�� ��
                start[0]--;
            }
        }
        else if (s == "right") {
            if (max_width >= start[0] + 1) {
                start[0]++;
            }
        }
        else if (s == "up") {
            if (max_height >= start[1] + 1) {
                start[1]++;
            }
        }
        else if (s == "down") {
            if (min_height <= start[1] - 1) {
                start[1]--;
            }
        }
    }

    // return answer;
    return start;
}


// ������ Ǯ��
vector<int> move(vector<int> cur, string key, vector<int> board) {
    if (key == "down") {
        if (cur[1] > -board[1] / 2) {
            cur[1]--;
        }
    }
    else if (key == "up") {
        if (cur[1] < board[1] / 2) {
            cur[1]++;
        }
    }
    else if (key == "left") {
        if (cur[0] < -board[0] / 2) {
            cur[0]--;
        }
    }
    else if (key == "right") {
        if (cur[0] < board[0] / 2) {
            cur[0]++;
  
      }
    }
}

// �̿� ����
vector<int> professor_solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    answer.push_back(0);


    return answer;
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