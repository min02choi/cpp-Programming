#include <string>
#include <vector>

using namespace std;

// 10������ �޾� ��Ʈ(string)�� ��ȯ���ִ� �Լ�
string decToBit(int n) {
    char c;
    int div;
    while (true) {
        int number = n / 2; // ���� ����


    }
}

// �� ��Ʈ�� ���Ͽ� ���̰� 1~2�� ���� true ��ȯ
bool bitCompare(string bit1, string bit2) {

}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int cnt = 0;
    int num = 0;

    for (int i = 0; i < numbers.size(); i++) {
        string bit = decToBit(numbers[i]);      // 10������ 2���� ��Ʈ�� ��ȯ
        
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