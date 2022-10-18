#include <iostream>
#include <vector>

using namespace std;

// ���� ����
void test1(int a) {
	a++; 
}
void test2(int& a) {
	a++;
}

// ���� ����
void vec_test1(vector<int> a) {		// ���⿡ const�ص� ������?
	a.push_back(100);
}
void vec_test2(vector<int>& a) {
	a.push_back(100);
}


int main() {

	// ���� ����
	int i = 0;
	int j = 0;
	test1(i);
	test2(j);

	cout << "i: " << i << endl;
	cout << "j: " << j << endl;


	// ���� ����
	vector<int> a;
	vector<int> b;
	vec_test1(a);
	vec_test2(b);

	cout << "i: " << a.size() << endl;
	cout << "j: " << b.size() << endl;

	// ������ġ: const ���̱�
	// �ð��� �Ʊ��ϱ� ������ �����°��� ���� �ٲٶ�� ��Ⱑ �ƴϰŵ�? �׷��� ���� ���� �ٲܷ��� �õ��� ������ �����Ϸ� �ϰ� �� ���ƶ�
	// �����ϴ� �ð��� �����ϱ� ����. �Լ� �ȿ��� ��ȸ�� �ϵ�, ������ ���ϰԲ�
	// ���� �õ��� ������ �����Ϸ��� ������ �����
}