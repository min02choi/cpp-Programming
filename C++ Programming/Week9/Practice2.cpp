#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int width = 0, height = 0;

    // 내부 정렬
    for (int i = 0; i < sizes.size(); i++) {
        sort(sizes[i].begin(), sizes[i].end());
    }

    for (int i = 0; i < sizes.size(); i++) {
        if (width < sizes[i][0]) {
            width = sizes[i][0];
        }
        if (height < sizes[i][1]) {
            height = sizes[i][1];
        }
    }

    answer = height * width;

    return answer;
}

int professor_solution(vector<vector<int>> sizes) {
    int answer = 0;
    int minmax = -1;
    int maxmax = -1;

    
    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            if (sizes[i][0] > maxmax) maxmax = sizes[i][0];
            if (sizes[i][1] > minmax) minmax = sizes[i][1];
        }
        else {
            if (sizes[i][1] > maxmax) maxmax = sizes[i][1];
            if (sizes[i][0] > minmax) minmax = sizes[i][0];
        }
    }

    answer = minmax * maxmax;
    return answer;
}