#include <iostream>
#include <string>
#include <vector>

/*
    ���� ��¥: 2022-11-22

    ��ӿ� ��ӿ� ���..
    virtual �Լ� -> �ش� �Լ��� �θ� ��ü�� Ŭ������ �Լ� ȣ��
*/

using namespace std;

/////// Class ///////

class Utility {
public:
    static bool isDiv(int a, int b);
    static bool isPrime(int a);         // a�� �Ҽ��ΰ�?
};

class P : public Utility {
protected:
    int n;
public:
    P(int n);    // a�� b�� ���������°�?
    virtual int solution() = 0;         // a�� �Ҽ��ΰ�?
};

class P8 : public P {
public:
    P8(int n);
    virtual int solution();
};

class P10 : public P8 {
public:
    P10(int n);
    virtual int solution();
};

class P9 : public P {
protected:
    int m;
public:
    P9(int n, int m);
    virtual int solution();
};

class P92 : public P9 {
public:
    P92(int n, int m);
    virtual int solution();
};

/////// Class ���� ///////

/* class Utility ���� */
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

/* class P ���� */
P::P(int n) {
    this->n = n;
}


/* class P8 ���� */
P8::P8(int n) : P(n) {
    ;
}
    
int P8::solution() {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}

/* class P10 ���� */
P10::P10(int n) : P8(n) {
    ;
}

int P10::solution() {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (isDiv(n, i)) {
            sum += i;
        }
    }
    return sum;
}

/* class P9 ���� */
P9::P9(int n, int m) : P(n) {
    this->m = m;
}

int P9::solution() {
    int gcd = 1;
    for (int i = 2; i <= n; i++) {
        if (isDiv(n, i) && isDiv(m, i)) {
            gcd = i;
        }
    }
    return gcd;
}

/* class P92 ���� */
P92::P92(int n, int m) : P9(n, m) {
    ;
}

int P92::solution() {
    int gcd = P9::solution();
    return n * m / gcd;
}

int main() {

    P* first, * second;

    cout << "12, 4: " << Utility::isDiv(12, 4) << endl;
    cout << "13, 4: " << Utility::isDiv(13, 4) << endl;
    cout << "12: " << Utility::isPrime(12) << endl;
    cout << "13: " << Utility::isPrime(13) << endl;

    // P8
    first = new P8(10);
    second = new P8(5);

    cout << "P8, 10: " << first->solution() << endl;
    cout << "P8, 5: " << second->solution() << endl;

    delete first;
    delete second;

    // P9
    first = new P9(12, 6);
    second = new P9(13, 7);

    cout << "P9, 12, 6: " << first->solution() << endl;
    cout << "P9, 13, 7: " << second->solution() << endl;

    delete first;
    delete second;


    return 0;

} 