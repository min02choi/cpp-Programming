#include <string>
#include <vector>

/*
    숫자로 주어진 나이를 알파벳으로 바꾸어라
    (단, a:0, b:1, ... j:9)
*/

using namespace std;

string solution(int age) {
    string answer = "";
    vector<string> alpha = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };
    int temp;

    while (age > 0) {
        temp = age % 10;
        answer = alpha[temp] + answer;
        age /= 10;
    }

    return answer;
}

// 교수님 코드
// 아스키 코드 값을 사용(a에서 인덱스 값을 더함)
string professor_solution(int age) {
    string answer = "";
    for (int i = age; i > 0; i /= 10) {
        answer = (char)('a' + i % 10) + answer;
    }
    return answer;
}

/*
    - 타입캐스팅(type casting)
    어떻게 해석할 지에 따라 의미가 달라짐

    - ... 타입캐스팅(inplicit type casting)
    컴파일러에게 typecasting을 맡김

    - 명시적 타입캐스팅(explicit type casting)
    명시적으로 이것이 어떤 타입인지 알려주는 것
    모호함을 줄이는 것
*/
