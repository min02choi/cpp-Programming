#include <string>
#include <vector>

using namespace std;



vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int temp = 0;
    int total = 0;

    for (int a = 0; a < arr1.size(); a++) {     // a�� ���� �ٺ�(��)
        for (int i = 0; i < arr1[0].size(); i++) {  // i�� ���� sub


            for (int j = 0; j < arr2.size(); j++) {     // j�� ���� sub
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

// ������ �־��� ����
// ���ΰ� Ŭ������ �־����� Ŭ���� ���θ� ä���־�� ��