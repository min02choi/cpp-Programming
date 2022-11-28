#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Practice10 : public Practice8 {
public:
    Practice10(int n);
    virtual int solution();
};

class Practice9 : public P {
protected:
    int m;
    // int n;
public:
    Practice9(int n, int m);
    int solution();
};

Practice9::Practice9(int n, int m) {
    this->m = m;
    // this->n = n;
}

int Practice9::solution() {
    int gcd = 1;
    for (int i = 2; i <= n; i++) {
        if (isDiv(n, i) && isDiv(m, i)) {
            gcd = i;
        }
    }
    return gcd;
}

/*
    
*/