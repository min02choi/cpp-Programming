#include <iostream>
#include <string>
#include <vector>


using namespace std;


//// 클래스 ////

class FX {
protected:
    long long n;
    int diff(long long n, long long i);
    virtual int limit();
public:
    FX(long long n);
    long long solution();
};

// 상속을 이용하여 비트 3개까지 허용하겠음
class FX2 : public FX {
protected:
    virtual int limit();
public:
    FX2(long long n);
};


//// class 구현 ////

/* class FX 구현 */
FX::FX(long long n) {
    this->n = n;
}

long long FX::solution() {
    long long i;
    for (i = n + 1; diff(n, i) > limit(); i++) {
    }
    return i;
}

int FX::diff(long long n, long long i) {
    int count = 0;
    int len = sizeof(n) * 8;
    long long mask = 1;
    for (int j = 0; j < len; j++) {
        if ((n & mask) != (i & mask)) {
            count++;
        }
        mask = mask << 1;
    }
    return count;
}

int FX::limit() {
    return 2;
}

/* class FX2 구현 */

FX2::FX2(long long n) : FX(n) {
    // this->n = n;
}

int FX2::limit() {
    return 3;
}

/*
long long FX::solution() {
    long long i;
    for (i = n + 1; diff(n, i) > 3; i++) {
    }
    return i;
}
*/

int main() {

    long long n = 7;
    FX myFX(n);
    cout << n << ":" << myFX.solution() << endl;
    
    FX2 myFX2(n);
    cout << n << ":" << myFX2.solution() << endl;

    return 0;

}

