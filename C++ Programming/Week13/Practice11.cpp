#include <iostream>
#include <vector>
#include <algorithm>

/*
    virtual, 상속
*/

using namespace std;
/*
int solution(vector<vector<int>> board)
{
    int answer = 1234;
    int minlen = board.size();
    if (minlen > board[0].size()) {
        minlen = board[0].size();
    }
    int square;
    int idx = 0;

        for (int i = idx; i < idx + minlen - 1; i++) {
            
            if (board[줄][i] == 0) {
                idx++;
                break;
            }
            
        }

    return answer;
}
*/
///////////////////////////////////////////////////////////////////////////////////

class Practice11 {
protected:
    vector<vector<int>> table;
    int width, height;
    virtual int getArea(int top, int left);     // 현재 오브젝트가 부른 getArea 호출
    // bool isSquare(int top, int left, int bottom, int right);
    bool isCorrectSize(int top, int left, int bottom, int right);
    virtual bool isWhatIWant(int top, int left, int bottom, int right);
public:
    Practice11(vector<vector<int>> table);
    int solution();

};

class Practice11_2 : public Practice11 {
    virtual int getArea(int top, int left);     // 현재 오브젝트가 부른 getArea 호출
    bool isRect(int top, int left, int bottom, int right);
public:
    Practice11_2(vector<vector<int>> table);
    
    // int solution();      // virtual 로 대체하면 중복 코드를 대체할 수 있음
};

/* class Practice11 */
Practice11::Practice11(vector<vector<int>> table) {
    this->table = table;
    width = table[0].size();
    height = table.size();
    
}
int Practice11::getArea(int top, int left) {
    int maxarea = 0;
    for (int j = left; j < width; j++) {
        for (int i = top; i < height; i++) {
            if (isWhatIWant(top, left, i, j)) {     // isWhatIWant로 수정
                int area = (i - top + 1) * (j - left + 1);
                if (area > maxarea) {
                    maxarea = area;
                }
            }
        }
    }
    return maxarea;
}
/* isWhatIwant
bool Practice11::isSquare(int top, int left, int bottom, int right) {
    if ((bottom - top) != (right - left)) {
        return false;
    }
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (table[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
*/

bool Practice11::isWhatIWant(int top, int left, int bottom, int right) {
    if ((bottom - top) != (right - left)) {
        return false;
    }
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (table[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

int Practice11::solution() {
    int maxarea = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int area = getArea(i, j);
            if (area > maxarea) {
                maxarea = area;
            }
        }
    }
    return maxarea;
}

bool Practice11::isWhatIWant(int top, int left, int bottom, int right) {

}

/* class Practice11_2 */
Practice11_2::Practice11_2(vector<vector<int>> table) : Practice11(table)
{
    ;
}

int Practice11_2::getArea(int top, int left) {
    int maxarea = 0;
    for (int j = left; j < width; j++) {
        for (int i = top; i < height; i++) {
            if (isRect(top, left, i, j)) {
                int area = (i - top + 1) * (j - left + 1);
                if (area > maxarea) {
                    maxarea = area;
                }
            }
        }
    }
    return maxarea;
}
bool Practice11_2::isRect(int top, int left, int bottom, int right) {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            if (table[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}
/* virtual 로 대체하면 중복 코드를 대체할 수 있음
int Practice11_2::solution() {
    int maxarea = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int area = getArea(i, j);
            if (area > maxarea) {
                maxarea = area;
            }
        }
    }
    return maxarea;
}
*/

int main() {
    vector<int> row;
    vector<vector<int>> table;
    
    row.push_back(0);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    table.push_back(row);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    table.push_back(row);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    row.push_back(1);
    table.push_back(row);
    row.push_back(0);
    row.push_back(0);
    row.push_back(1);
    row.push_back(0);
    table.push_back(row);

    Practice11 myPractice11(table);
    Practice11_2 myPractice11_2({ {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {0, 0, 1, 0} });
    
    cout << myPractice11.solution() << endl;
    cout << myPractice11_2.solution() << endl;

    return 0;

}

/*
    isSquare -> 이름이 너무 사각형에만 있는 함수이다.
    미래를 예측하여 상속받을 수 있을 경우를 대비하여 코딩.
    상속시에 유리한 코딩을 미리미리 해놓는 게 좋음
    클래스 재설계할 필요도 있음

    왜 virtual로 바꾸어야하는지, 상속에 대해서도
*/