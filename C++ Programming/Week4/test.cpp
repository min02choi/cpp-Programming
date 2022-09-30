#include <iostream>
#include <typeinfo>

// string을 인덱스로 반환하면 char 형 반환

using namespace std;

int main() {
	string word = "abcd";

	cout << typeid(word[1]).name() << endl;
}