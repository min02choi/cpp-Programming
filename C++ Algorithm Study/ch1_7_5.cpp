#include <iostream>
#include <list>

using namespace std;

void init_mix_card(list<int> &card) {        // ������ �ؾ���
    
    // �����̳� �ȿ� ī�� ����(�ʱ�ȭ...?)
    // �ٵ� �ʱ�ȭ ��� ���� ��ü ������ �� �ؾ��ϴ°� �ƴѰ�
    for (int i = 1; i < 14; i++) {      // ī�� ������ ���� �� �𸣰ھ 1~13 ������ ����
        card.push_back(i);              // �����̳� �ȿ� ī�� ����
    }

    // ī��(list) �������� ����

    // ���� : list ����Ʈ
    for (auto i : card) {
        cout << i << " ";
        }
    cout << endl;

}

// �������� �������Ƿ� �տ������� ����
// �ƴ� �̰� p�ֵ� �ϳ��� ����� ��
void select_card(const list<int>& card, int selected[4]) {
    selected = card.front()
}

int main() {

    // �� ���� �����̳� ��ü ����
    list<int> p1;
    list<int> p2;
    list<int> p3;
    list<int> p4;

    

    // ������ ī�� �ʱ�ȭ, ����
    // ������ �迭�̳� �� �׷��ɷ� ����
    init_mix_card(p1);
    init_mix_card(p2);
    init_mix_card(p3);
    init_mix_card(p4);

    /*
    for (auto i : p1) {
        cout << i << " ";
        cout << endl;
    }
    */

    // cout << "p1.front()" << p1.front() << endl;
    //cout << p1.back() << endl;

    int selected[4];    // ���õ� ī�带 �����ϱ� ���� �迭





    

}