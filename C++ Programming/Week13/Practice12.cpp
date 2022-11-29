#include <string>
#include <vector>

using namespace std;

// 10진수로 받아 비트(string)로 변환해주는 함수
string decToBit(int n) {
    char c;
    int div;
    while (true) {
        int number = n / 2; // 몫이 나옴


    }
}

// 두 비트를 비교하여 차이가 1~2개 나면 true 반환
bool bitCompare(string bit1, string bit2) {

}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int cnt = 0;
    int num = 0;

    for (int i = 0; i < numbers.size(); i++) {
        string bit = decToBit(numbers[i]);      // 10진수를 2진수 비트로 변환
        
        for (int j = numbers[i]; ; j++) {
            string comp = decToBit(j);

            if (bitCompare(bit, comp)) {
                num = j;
            }
        }
        answer.push_back(num);
    }


    return answer;
}

int main() {

}