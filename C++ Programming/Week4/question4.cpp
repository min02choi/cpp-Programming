#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 풀이 전략 : 중앙값을 구한 뒤, 배열의 첫 번쨰 요소를 구하고 해당 수 부터 num만큼의 배열을 생성
vector<int> solution(int num, int total) {

    vector<int> answer;
    int temp = (total / num) - (num / 2);
    
    // if num is even
    if (num % 2 == 0) {
        temp += 1;
    }

    for (int i = temp; i < temp + num; i++) {
        answer.push_back(i);
    }
    
    return answer;
}

// 무식하게 구하기
int sum(int i, int sum) {
    int total = 0;
    for (int j = 0; j < sum; j++) {

    }
}

vector<int> solution2(int num, int total) {
    
}


int main() {
    int num = 3, total = 12;
    vector<int> answer;

    answer = solution(num, total);
    for (int i : answer) {
        cout << i << " ";
    }

    cout << endl;
    
}