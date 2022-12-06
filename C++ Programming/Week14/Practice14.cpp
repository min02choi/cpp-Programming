#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Practice14 {
    string path;
    vector<char> numpath;
    int xPos = 0;
    int yPos = 0;
public:
    Practice14(string path);
    int solution(string dirs);
    bool isOutofRange();
    int curPos();
    int pathToVec();
};

Practice14::Practice14(string path) {
    this->path = path;
}

int Practice14::pathToVec() {
    for (int i = 0; i < path.length(); i++) {
        numpath.push_back(path[i]);
    }
}

int Practice14::solution(string dirs) {
    int answer = 0;

    for (int i = 0; i < path.length(); i++) {
        if (path[i] == 'U') {
            if (!isOutofRange()) {
                xPos += 1;
            }
        }
        else if (path[i] == 'D') {
            if (!isOutofRange()) {
                xPos -= 1;
            }
        }
        else if (path[i] == 'R') {
            if (!isOutofRange()) {
                yPos += 1;
            }
        }
        else if (path[i] == 'L') {
            if (!isOutofRange()) {
                yPos -= 1;
            }
        }
    }

    return answer;
}


int main() {

}

// 시험 볼 때는 solution함수를 편집하면 안됨
// 변경 되었을 때는 0점 처리