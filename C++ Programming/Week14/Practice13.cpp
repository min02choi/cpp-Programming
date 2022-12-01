#include <string>
#include <vector>

using namespace std;



vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int temp = 0;
    int total = 0;

    for (int a = 0; a < arr1.size(); a++) {     // a는 왼쪽 근본(행)
        for (int i = 0; i < arr1[0].size(); i++) {  // i는 왼쪽 sub


            for (int j = 0; j < arr2.size(); j++) {     // j는 왼쪽 sub
                temp = arr1[a][i] * arr2[i][0];
                
            }

        }
    }

    for (int i = 0; i < arr2.size(); i++) {
        for (int j = 0; j < arr2[0].size(); j++) {

        }
    }

    return answer;
}

// 메인이 주어질 것임
// 메인과 클래스가 주어지고 클래서 내부를 채워넣어야 함