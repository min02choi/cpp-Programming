#include <string>
#include <vector>
#include <iostream>

using namespace std;

class overflowError {};
class incorrectInput {};

int product(int from, int count) {
    int answer = 1;
    int temp;
    for (int i = 0; i < count; i++) {
        temp = answer * (from - i);
        if (temp < answer) throw overflowError();
        answer = temp;
    }
    return answer;
}

int solution(int balls, int share) {
    int answer;

    if (balls < share) {

    }

    try {
        int a = product(balls, share);
        int b = product(share, share);
        answer = a / b;
    }
    catch (overflowError e) {
        cout << "OverFlow Error" << endl;
        return -1;
    }
    catch (...) {
        cout << "Error: " << balls << " " << share << endl;
    }
    return answer;
}

int main() {
    int balls, share;
    cin >> balls >> share;

    try {
        cout << solution(balls, share);
    }
    catch (incorrectInput e) {
        cout << "Incorrect Input: " << balls << " " << share << endl;
    }

}