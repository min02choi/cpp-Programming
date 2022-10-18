#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    int max_cnt = 0, max_num;
    int fir_cnt = 0, fir_num;

    sort(array.begin(), array.end());
    fir_num = array[0];
    max_num = fir_num;

    for (int i = 0; i < array.size(); i++) {

        if (fir_num == array[i]) {     // 이전과 이어지는 수
            fir_cnt++;
        }
        else if (fir_num != array[i]) {

            if (max_cnt > fir_cnt) {
                // fir_cnt =
            }
            else if (max_cnt == fir_cnt) {

            }
            else {

            }
        }
    }

    return answer;
}

int professor_solution(vector<int> array) {
    int answer = 0;
    int count[1000] = { 0, };
    int mode = -1;
    int modecnt = -1;
    bool duplicate = 0;

    for (int i = 0; i < 1000; i++) {
        count[i] = false;
    }
    for (int i = 0; i < array.size(); i++) {    // array값에 해당하는 cnt의 값을 증가
        count[array[i]]++;
    }
    for (int i = 0; i < 1000; i++) {        
        if (count[i] > modecnt) {
            mode = i;
            modecnt = count[i];
            duplicate = false;
        }
        else if (count[i] == modecnt) {
            duplicate = true;
        }
    }

    if (duplicate == true) {
        answer = -1;
    }
    else {
        answer = mode;
    }

    return answer;
}

int professor_solution2(vector<int> array) {
    int answer = 0;
    int count[1000] = { 0, };
    int mode;
    int modecnt = -1;
    bool duplicate = 0;

    for (int i = 0; i < array.size(); i++) {
        int count = 0;
        for (int j = i; j < array.size(); j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > modecnt) {
            mode = array[i];
            modecnt = count;
            duplicate = false;
        }
        else if (count == modecnt) {
            duplicate = true;
        }
    }

    if (duplicate == true) {
        answer = -1;
    }
    else {
        answer = mode;
    }

    return answer;
}


int main() {

}