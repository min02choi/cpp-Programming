#include <iostream>
#include <string>
#include <vector>

/*
    �� ���ڸ� �޾Ƽ� ������ �ִ������� �ּҰ������ ���ϴ� �Լ�
*/


using namespace std;

vector<int> mysolution(int n, int m) {
    vector<int> answer;
    int minnum = m;
    if (minnum > n) {
        minnum = n;
    }
    int max;    // �ִ�����
    int min;    // �ּҰ����

    // �ִ�����
    for (int i = 1; i <= minnum; i++) {
        if (n % i == 0 && m % i == 0) {
            max = i;
        }
    }
    min = n * m / max;

    answer.push_back(max);
    answer.push_back(min);

    return answer;
}

////////// class�� �̿��� ���� /////////////////////////////////////////////////////

class Utility {
public:
    static bool isDiv(int a, int b);
    static bool isPrime(int a);         // a�� �Ҽ��ΰ�?

};

class Practice8 {
    int n;
public:
    Practice8(int n);    // a�� b�� ���������°�?
    int solution();         // a�� �Ҽ��ΰ�?
};
bool Utility::isDiv(int a, int b) {
    return a % b == 0;
}
bool Utility::isPrime(int a) {
    int i;
    for (i = 2; i < a; i++) {
        if (isDiv(a, i)) {
            break;
        }
    }
    if (i == a) {       // �ڱ� �ڽ��̸� �Ҽ�
        return true;
    }
    else {
        return false;
    }
}

Practice8::Practice8(int n) {
    this->n = n;
}
int Practice8::solution() {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (Utility::isPrime(i)) {
            count++;
        }
    }
    return count;
}

int main() {
    cout << "12, 4:" << Utility::isDiv(12, 4) << endl;
    cout << "2, 5:" << Utility::isDiv(2, 5) << endl;

    Practice8(10);
}