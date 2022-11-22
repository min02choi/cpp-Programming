#include <iostream>
#include <string>
#include <vector>

/*
    숫자 n을 입력받고 약수의 합을 리턴
*/

// virtual 이 아닐 때 발생하는 문제점

// 2022-11-22 수업 폰에 사진 찍어놓음

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

////////// class을 이용한 구현 /////////////////////////////////////////////////////

class Utility {
public:
    static bool isDiv(int a, int b);
    static bool isPrime(int a);         // a가 소수인가?

};

class Practice8 {
    int n;
public:
    Practice8(int n);    // a가 b로 나누어지는가?
    int solution();         // a가 소수인가?
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
    if (i == a) {       // 자기 자신이면 소수
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
    < 클래스 사용 권장 >
    함수로 사용했을 때에는 ctrl + c, v를 했어야 함. 이를 하면 만약 함수 수정 시 함수를 사용한 코드파일에서는 전부 다 수정해야 함
    클래스를 활용할 때에는 상속하수가 있음 그래서 만약에 이를 수정한다면 상속을 받은 클래스들은 자동적으로 수정 됨
    기능의 확장성이 높아짐
*/