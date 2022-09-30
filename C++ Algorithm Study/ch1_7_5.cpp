#include <iostream>
#include <list>

using namespace std;

void init_mix_card(list<int> &card) {        // 참조로 해야함
    
    // 컨테이너 안에 카드 삽입(초기화...?)
    // 근데 초기화 라는 것은 객체 생성할 때 해야하는거 아닌가
    for (int i = 1; i < 14; i++) {      // 카드 범위가 뭔지 잘 모르겠어서 1~13 정수로 설정
        card.push_back(i);              // 컨테이너 안에 카드 삽입
    }

    // 카드(list) 무작위로 섞기

    // 실험 : list 프린트
    for (auto i : card) {
        cout << i << " ";
        }
    cout << endl;

}

// 무작위로 섞었으므로 앞에서부터 참조
// 아니 이거 p애들 하나로 묶어야 함
void select_card(const list<int>& card, int selected[4]) {
    selected = card.front()
}

int main() {

    // 네 개의 컨테이너 객체 생성
    list<int> p1;
    list<int> p2;
    list<int> p3;
    list<int> p4;

    

    // 각각의 카드 초기화, 섞기
    // 변수들 배열이나 뭐 그런걸로 묶기
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

    int selected[4];    // 선택된 카드를 저장하기 위한 배열





    

}