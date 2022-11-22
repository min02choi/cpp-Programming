#include <iostream>
#include <string>
#include <vector>

/*
    ���� n�� �Է¹ް� ����� ���� ����
*/

// virtual �� �ƴ� �� �߻��ϴ� ������

// 2022-11-22 ���� ���� ���� ������

using namespace std;

int mysolution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            answer += i;
        }

    }

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

class Practice10 : public Practice8 {
public:
    Practice10(int n);
    int solution();
};

class P : public Utility {
protected:
    int n;
public:
    P(int n);
    virtual int solution();
}
Practice10::Practice10(int n) : Practice8(n) {
    
}
int Practice10::solution() {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        // if ()
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
/*
    < Ŭ���� ��� ���� >
    �Լ��� ������� ������ ctrl + c, v�� �߾�� ��. �̸� �ϸ� ���� �Լ� ���� �� �Լ��� ����� �ڵ����Ͽ����� ���� �� �����ؾ� ��
    Ŭ������ Ȱ���� ������ ����ϼ��� ���� �׷��� ���࿡ �̸� �����Ѵٸ� ����� ���� Ŭ�������� �ڵ������� ���� ��
    ����� Ȯ�强�� ������
*/