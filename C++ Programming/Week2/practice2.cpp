// ===============================
  /*
    ���� ��¥ : 22.09.13
  */
  // ===============================


#include <iostream>

using namespace std;

// �� ���� �Է¹޾� ���� ������� �����Ͻÿ�.

int main() {
    int val1, val2, val3;
    int largest, smallest, middle;

    cout << "Please enter three integers with space between.: ";
    cin >> val1 >> val2 >> val3;

    if (val1 > val2) {
        if (val1 > val3) {
            largest = val1;

            if (val2 > val3) {
                middle = val2;
                smallest = val3;
            }
            else {
                middle = val3;
                smallest = val2;
            }
        }
    }
    else {
        if (val2 > val3) {
            largest = val2;

            if (val1 > val3) {
                middle = val1;
                smallest = val3;
            }
            else {
                middle = val3;
                smallest = val1;
            }
        }
    }

    cout << smallest << ", " << middle << ", " << largest << endl;
}