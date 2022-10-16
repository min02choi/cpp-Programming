#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int balls, int share) {
    int answer = 0;
    int dem = 1, int nom = 1;

    int top = balls;                // 분자 최대 시작점
    int top_cnt = balls - share;    // 분모 곱해야 하는 개수
    int bot = balls - share;        // 분모 최대 시작점
    int bot_cnt = balls - share;    // 분자 곱해야 하는 개수

    while (true) {

        if (top_cnt == 0) {
            break;
        }

        if (top_cnt != 0) {
            dem = dem * top;
            top--;
            top_cnt--;
        }

        if (bot_cnt != 0) {
            nom = nom * bot;
            bot--;
            bot_cnt--;
        }

        int temp;
        int min = dem;
        if (dem > nom) {
            min = nom;
        }
        for (int i = 1; i < min; i++) {
            if (dem % i == 0 && nom % i == 0) {
                dem /= i;
                nom /= i;
            }
        }
        answer = dem / nom;
    }

    return answer;

}


long long product(int from, int count) {
    long long answer = 1;
    for (int i = 0; i < count; i++) {
        answer = answer * (from - i);
    }
    return answer;
}

int professor_solution(int balls, int share) {
    long long answer = product(balls, share) / product(share, share);

    return answer;
}

int main() {
    int balls = 50;
    int share = 10;
    
    cout << solution(balls, share) << endl;

    return 0;
}