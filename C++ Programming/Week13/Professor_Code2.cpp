#include <iostream>
#include <string>
#include <vector>

/*
	수업 날짜: 2022-11-24

    * 문제: table이 주어지고 이 table안에서 구할 수 있는 가장 큰 정사각형/직사각형을 구하시오.
    상속, 오버라이딩
*/

using namespace std;

/////// Class ///////

class P11 {
protected:
    vector<vector<int>> table;
    int width, height;
    int getArea(int top, int left);     // 현재 오브젝트가 부른 getArea 호출
    virtual bool isCorrectSize(int top, int left, int bottom, int right);
    bool isWhatIWant(int top, int left, int bottom, int right);
public:
    P11(vector<vector<int>> table);
    int solution();
};

class P11_2 : public P11 {
    virtual bool isCorrectSize(int top, int left, int bottom, int right);
public:
    P11_2(vector<vector<int>> table);
};


/////// Class 구현 ///////

/* class P11 구현 */
P11::P11(vector<vector<int>> table) {
    this->table = table;
    width = table[0].size();
    height = table.size();
}

int P11::solution() {
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

int P11::getArea(int top, int left) {
    int maxarea = 0;
    for (int j = left; j < width; j++) {
        for (int i = top; i < height; i++) {
            if (isWhatIWant(top, left, i, j)) {
                int area = (i - top + 1) * (j - left + 1);
                if (area > maxarea) {
                    maxarea = area;
                }
            }
        }
    }
    return maxarea;
}

bool P11::isWhatIWant(int top, int left, int bottom, int right) {
    if (!isCorrectSize(top, left, bottom, right)) {
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

bool P11::isCorrectSize(int top, int left, int bottom, int right) {
    if ((bottom - top) != (right - left)) {
        return false;
    }
    return true;
}

/* class P11_2 구현 */
P11_2::P11_2(vector<vector<int>> table) : P11(table) {
    ;
}

bool P11_2::isCorrectSize(int top, int left, int bottom, int right) {
    return true;
}


///////////////////////////////////////////////////////////////

int main() {

    vector<int> row;
    vector<vector<int>> table;

    table = {
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 0, 0, 1, 0 } };
    
    P11 myP11(table);
    P11_2 myP11_2(table);

    cout << myP11.solution() << endl;
    cout << myP11_2.solution() << endl;

    return 0;

}