#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Ǯ�� ���� : �߾Ӱ��� ���� ��, �迭�� ù ���� ��Ҹ� ���ϰ� �ش� �� ���� num��ŭ�� �迭�� ����
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

// �����ϰ� ���ϱ�
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