#include <iostream>
#include <string>
#include <vector>

/*
    Practice5 �� '���' ����

    �Ѷ��Ѷ� �����ϱ� ����� -> ��ӹ���
    ��ӹ��� �� ���� �ʿ��� �͸� �߰��ϰ� overriding�ϸ� ��
*/

using namespace std;

class MyString {
protected:      // �ڽ�Ŭ�������� ������ �� �ְ� ��
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
    int len = this->string::length();       // ���� stringŬ������ length. this ��� ��

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

// �ڱ��ڽ��� return�� �ϱ� ���� ostream�� �����ؾ� ��
// cout�� �ƴ� ostream����
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

    // �����δ� FiveString�� ��������Ű����� ����� �θ� Ŭ������ String object�� �������
    // �ݵ�� �θ� Ŭ������ object�� �Ҹ�(�θ� Ŭ������ constructor�� �Ҹ�)
    // ���� ������ ���� ������ default constructor�� �Ҹ�
    // �θ�Ŭ������ constructor�� ������ �� ����
    FiveString p5my("123456");      // object����
    // p5my.setString("1234");

    cout << my.length() << ":" << my.getPstr() << endl;
    cout << my.length() << ":" << my << endl;               // friend ���

    // �Ʒ� p5my
    // string Ŭ������� �����ϰ� ���
    cout << p5my.length() << ":" << p5my << ":" << p5my.solve() << endl;

    return 0;

}

/*
    ����� ������ ������ �θ� ����� ����.
    �θ��� constructor�� destructor�� �׻� �Ҹ��� ��

    �ڽ��� �θ�κ��� �������� �ʴ� ��
    1. �θ��� constructor�� destructor
    2. �θ��� friend�� ���� friend�� �ƴ�
    3. assignment object�� �������� ����
*/

