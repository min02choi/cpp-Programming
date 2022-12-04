#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
	sort(array.begin(), array.end());

	int i = array[0];
	int num = array[0];
	int cur_cnt = 0;
	int cnt = 0;
	bool flag = 0;
	int max_num;

	for (i = 1; i < array.size(); i++) {
		if (i == 1) {
			cnt++;
		}

		if (num == array[i]) {
			cnt++;
			num = array[i];
			max_num = array[i];
		}
		else {
			if (cnt > cur_cnt) {
				cur_cnt = cnt;
				max_num = array[i];
				cnt = 0;
				flag = 0;
			}
			else if (cnt == cur_cnt) {
				cnt = 0;
				flag = 1;
			}
		}
	}
	if (flag == 1) {
		return -1;
	}
	return max_num;
}

int solution(vector<int> array) {
	
	int cnt[1000] = { 0, };
	bool flag = 0;

	for (int i = 0; i < array.size(); i++) {
		cnt[array[i]]++;
	}

	int i = 0;
	int max_num = i;
	int max_cnt;
	int bef_cnt = cnt[0];
	int count = -1;
	for (i = 1; i < 1000; i++) {
		if (bef_cnt < cnt[i]) {
			bef_cnt = cnt[i];
		}
		else if (bef_cnt == cnt[i]) {
			flag = 1;
		}
		else if (bef_cnt > cnt[i]) {
			flag = 0;
		}
	}
}

int main() {
	vector<int> num = { 1, 2, 3, 3, 3, 4 };
	solution(num);
}