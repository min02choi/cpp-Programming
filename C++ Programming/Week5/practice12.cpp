#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*
    ���� �迭 numbers�� ���� �� �� ���� ���� ���� �� �ִ� �ִ��� return�Ͻÿ�.
*/

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());       // �������� sort
    answer = numbers[0] * numbers[1];

    return answer;
}

// ������ Ǯ��
int professor_solution(vector<int> numbers) {
    int answer = 0;
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[i] * numbers[j] > answer) {
                answer = numbers[i] * numbers[j];
            }
        }
    }

    return answer;
}

int main() {
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    
    cout << "my answer : " << solution(numbers) << endl;
    cout << "pro answer : " << professor_solution(numbers) << endl;

    return 0;
}