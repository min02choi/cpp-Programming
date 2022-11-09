#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// 교수님의 풀이에 에라... 가 있음
// 근데 교수님껀 잘 됨

using namespace std;

int my_solution(int n) {
    int answer = 0;
    int copy = n;
    int res = 0;
    int left = 0;
    string num = "";

    while (copy >= 3) {
        res = copy / 3;
        left = copy % 3;
        num = to_string(left) + num;
        copy = res;
    }

    for (int i = 0; i < num.length(); i++) {

    }

    return answer;
}


// 인터넷 풀이
using namespace std;

int solution(int n) {
    int answer = 0;
    int div = 0;
    int res = 0;
    string s = "";
    div = n;

    while (div >= 3) {
        res = div % 3;
        div = div / 3;
        s += to_string(res);
    }

    s += to_string(div);

    int size = s.size();
    size--;

    for (auto x : s) {
        int n = x - '0';
        answer += n * pow(3, size--);
    }
    return answer;
}


// professor solution
class Number {
    private:
        string n;
        int k;
        // int getNum();
        
    public:
        Number(int n);
        void changeNum(int k);   
        string getN();
        void setNum(string n);
        void setNum(int n);
        int getNum();
};

class Converter {
    public:
        static string reverse(string str);
};

string Converter::reverse(string str) {
    string ret = "";
    for (int i = str.length() - 1; i >= 0; i--) {
        ret += str[i];
    }
    return ret;
}

Number::Number(int n) {
    this->k = 10;
    setNum(n);
}

void Number::setNum(int n) {
    this->n = "";
    for (int m = n; m > 0; m = m / 10) {
        this->n = (char)('0' + (m % 10)) + this->n;
    }
}


void Number::setNum(string n) {
    this->n = n;
}


int Number::getNum() {
    int i = 1;
    int num = 0;
    for (int m = n.length() - 1; m >= 0; m--) {
        num += (n[m] - '0') * i;
        i = i * k;
    }
    return num;
}

void Number::changeNum(int k) {
    int dec = getNum();
    this->k = k;
    this->n = "";

    for (int m = dec; m > 0; m = m / k) {
        this->n = (char)('0' + (m % k)) + this->n;
    }
}

string Number::getN() {
    return n;
}


int main() {

    Number mynum(125);
    cout << mynum.getN() << endl;
    
    mynum.changeNum(3);
    cout << mynum.getN() << endl;

    mynum.setNum(Converter::reverse(mynum.getN()));
    // cout << Converter::reverse(mynum.getN()) << endl;       // static은 굳이 object가 필요 없어서 :: 사용
    cout << mynum.getN() << endl;

    mynum.changeNum(10);

    cout << mynum.getN() << endl;
    // mynum.changeNum(10);

    cout << mynum.getNum() << endl;

    return 0;

}