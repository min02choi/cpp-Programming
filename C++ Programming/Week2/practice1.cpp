// ===============================
  /*
    강의 날짜 : 22.09.13
  */
// ===============================


#include <iostream>

using namespace std;

extern int j;   // 선언만 하는 것. 어딘가 j가 존재함. define은 안된것

// 두개의 수를 입력받아 두 수를 비교하시오.

int main() {
    cout << "Hello World" << endl;

    int val1, val2;
    int largest, smallest;
    cout << "Please enter two integers with space between.: ";
    cin >> val1 >> val2;

    if (val1 > val2) {
        largest = val1;
        smallest = val2;
    }
    else {
        largest = val2;
        smallest = val1;
    }

    cout << "largest:" << largest << endl;  // "\n"보다 endl 사용 권장 -> 머신 디펜던시 줄어듦
    cout << "smallest:" << smallest << endl;
    cout << "sum:" << (largest + smallest) << endl;     // 안전함을 위해 괄호 사용 권장
    cout << "difference:" << (largest - smallest) << endl;
    cout << "mul:" << (largest * smallest) << endl;
    cout << "ratio:" << (largest / smallest) << endl;
    
    return 0;
}