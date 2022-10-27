#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int n = arr[0];
    answer.push_back(n);
    for (int i = 1; i < arr.size(); i++) {
        if (n != arr[i]) {
            answer.push_back(arr[i]);
            n = arr[i];
        }
    }

    return answer;
}
