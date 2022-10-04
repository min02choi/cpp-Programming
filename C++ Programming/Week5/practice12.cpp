#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/*
    정수 배열 numbers의 원소 중 두 개를 곱해 만들 수 있는 최댓값을 return하시오.
*/

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    sort(numbers.begin(), numbers.end(), greater<int>());       // 역순으로 sort
    answer = numbers[0] * numbers[1];

    return answer;
}

// 교수님 풀이
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