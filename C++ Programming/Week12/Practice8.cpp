#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int flag;
    for (int i = 2; i <= n; i++) {
        flag = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            answer++;
        }
    }

    return answer;
}

////////// class�� �̿��� ���� /////////////////////////////////////////////////////

class Utility {
public:
    static bool isDiv(int a, int b);    // a�� b�� ���������°�?
    static bool isPrime(int a);         // a�� �Ҽ��ΰ�?
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

int main() {
    cout << "12, 4:" << Utility::isDiv(12, 4) << endl;
    cout << "2, 5:" << Utility::isDiv(2, 5) << endl;

    return 0;
}
/*
    
*/