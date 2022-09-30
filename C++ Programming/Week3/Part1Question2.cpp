#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<int> arr)
{
    bool answer = true;
    
    sort(arr.begin(), arr.end());

    if (arr[0] == 1) {
        for (int i = 0; i < arr.size() - 1; i++) {

            if (arr[i] + 1 != arr[i + 1]) {
                answer = false;
                break;
            }
        }
    }
    else {
        answer = false;
    }

    return answer;
}

// »ìÂ¦
bool not_sort(vector<int> arr) {

    vector<int> sample(arr.size(), 0);

    for (int i = 0; i < arr.size(); i++) {
        sample[arr[i]]++;
    }
    for (int n : sample) {
        if (n != 1) {
            return false;
        }
    }
    return true;
}

int main() {

    vector<int> arr = {4, 3, 2};
    cout << solution(arr) << endl;

}