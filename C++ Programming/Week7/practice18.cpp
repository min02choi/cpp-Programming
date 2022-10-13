#include <string>
#include <vector>

/*
    ���ڷ� �־��� ���̸� ���ĺ����� �ٲپ��
    (��, a:0, b:1, ... j:9)
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

// ������ �ڵ�
// �ƽ�Ű �ڵ� ���� ���(a���� �ε��� ���� ����)
string professor_solution(int age) {
    string answer = "";
    for (int i = age; i > 0; i /= 10) {
        answer = (char)('a' + i % 10) + answer;
    }
    return answer;
}

/*
    - Ÿ��ĳ����(type casting)
    ��� �ؼ��� ���� ���� �ǹ̰� �޶���

    - ... Ÿ��ĳ����(inplicit type casting)
    �����Ϸ����� typecasting�� �ñ�

    - ����� Ÿ��ĳ����(explicit type casting)
    ��������� �̰��� � Ÿ������ �˷��ִ� ��
    ��ȣ���� ���̴� ��
*/
