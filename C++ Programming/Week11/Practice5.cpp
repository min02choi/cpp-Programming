#include <iostream>
#include <string>
#include <vector>

/*
    Practice5 �� '���' ����
    
    �Ѷ��Ѷ� �����ϱ� ����� -> ��ӹ���
    ��ӹ��� �� ���� �ʿ��� �͸� �߰��ϰ� overriding�ϸ� ��
*/

using namespace std;

bool solution(string s) {
    bool answer = true;

    if (s.length() != 4 || s.length() != 6)

    for (char c : s) {
        if (!(c >= '0' || c <= '9')) {
            return false;
        }
    }
    return true;
}

// professor_solution
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
        friend ostream& operator << (ostream& a, const MyString &b);
};

class FiveString : public /*MyString*/ string {
    public:
        FiveString(const char* a);
        bool solve();
        int length();
};

// ���� �θ�Ŭ������ string constructor���� ó������ ��
// �θ�Ŭ������ constructor�� ������ �� ����
// �ݷ�":" �ϰ� �θ�Ŭ������ ���ϴ� �Ķ���Ϳ� �Բ� �ۼ�
FiveString::FiveString(const char* a) : string(a) { ; }     

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

/*
bool FiveString::solve() {
    int len = length();

    if (len == 4 || len == 6) {
        for (int i = 0; i < 10 && pstr[i] != '\0'; i++) {
            if (pstr[i] < '0' || pstr[i] > '9') {
                return false;
            }
        }
    }
    else {
        return false;
    }

    return true;
}
*/

// �������̵�
// ����� �� string�� ���� �ҽ��ڵ尡 �������� �ұ��ϰ� ����
// �θ�Ŭ������ ���� ����� ȣ���� �ϰ� �ʹٸ� "::"�� ����Ͽ� �θ� Ŭ������ ���
int FiveString::length() {
    return string::length() * 2;
}

MyString::MyString() {
    pstr = NULL;
    initPstr();
}

MyString::~MyString() {
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
    �ڽ�Ŭ������ �θ�Ŭ������ ô �� �� ����. �ֳ��ϸ� �ڽ� Ŭ���� �ȿ��� ������ �θ� Ŭ������ �ֱ� ������
*/