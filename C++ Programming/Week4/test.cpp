#include <iostream>
#include <typeinfo>

// string�� �ε����� ��ȯ�ϸ� char �� ��ȯ

using namespace std;

int main() {
	string word = "abcd";

	cout << typeid(word[1]).name() << endl;
}