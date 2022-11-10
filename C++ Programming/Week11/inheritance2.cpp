#include <iostream>
#include <string>
#include <vector>

/*
    Practice5 겸 '상속' 연습

    한땀한땀 구현하기 힘들다 -> 상속받자
    상속받은 후 내가 필요한 것만 추가하고 overriding하면 됨
*/

using namespace std;

class MyString {
protected:      // 자식클래스에서 접근할 수 있게 됨
    char* pstr;
    void initPstr();
public:
    MyString();
    ~MyString();
    int length();
    void setString(const char* t);
    char* getPstr();
    friend ostream& operator << (ostream& a, const MyString& b);
};

MyString::MyString() {
    cout << "MyString::MyString()" << endl;
}

class FiveString : public MyString {
public:
    FiveString();
    bool solve();
    
};

FiveString::FiveString() {
    cout << "FiveString::FiveString()" << endl;
}


bool FiveString::solve() {
    int len = this->string::length();       // 원래 string클래스의 length. this 없어도 됨

    if (len == 4 || len == 6) {
        for (int i = 0; i < 10 && (*this)[i] != '\0'; i++) {
            if ((*this)[i] < '0' || (*this)[i] > '9') {
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;
}


int FiveString::length() {
    return string::length() * 2;
}

MyString::MyString() {
    pstr = NULL;
    initPstr();
}

MyString::~MyString() {
    cout << "MyString::~MyString()" << endl;
    if (pstr != NULL) {
        delete[] pstr;
    }
}

void MyString::initPstr() {
    pstr = new char[10];
}

int MyString::length() {
    int i;
    for (i = 0; i < 10; i++) {
        if (pstr[i] == '\0') {
            break;
        }
    }
    return i;
}

void MyString::setString(const char* t) {
    for (int i = 0; i < 10; i++) {
        pstr[i] = t[i];
        if (t[i] == '\0') {
            break;
        }
    }
}

char* MyString::getPstr() {
    return pstr;
}

// 자기자신을 return을 하기 위해 ostream을 리턴해야 함
// cout이 아닌 ostream형태
ostream& operator << (ostream& a, const MyString& b) {
    a << b.pstr;
    return a;
}

/*
// ?
ostream& MyString::operator << (ostream& a) {
    a << pstr;
    return a;
}
*/


int main() {

    FiveString my;


    MyString my;
    my.setString("test");

    // 겉으로는 FiveString이 만들어진거같지만 사실은 부모 클래스인 String object가 만들어짐
    // 반드시 부모 클래스의 object도 불림(부모 클래스의 constructor도 불림)
    // 내가 선언을 하지 않으면 default constructor이 불림
    // 부모클래스의 constructor을 선택할 수 있음
    FiveString p5my("123456");      // object생성
    // p5my.setString("1234");

    cout << my.length() << ":" << my.getPstr() << endl;
    cout << my.length() << ":" << my << endl;               // friend 사용

    // 아래 p5my
    // string 클래스라고 간주하고 출력
    cout << p5my.length() << ":" << p5my << ":" << p5my.solve() << endl;

    return 0;

}

/*
    상속을 여러번 받으면 부모가 겹겹이 쌓임.
    부모의 constructor와 destructor은 항상 불리게 됨

    자식이 부모로부터 물려받지 않는 것
    1. 부모의 constructor와 destructor
    2. 부모의 friend는 나의 friend가 아님
    3. assignment object는 물려받지 않음
*/

