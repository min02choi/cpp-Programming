#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>


// 문제: Puzzle게임 구현
/*
	1 ~ 9 퍼즐 게임을 만들어서 섞고, 사용자가 맞추도록 함. 키들로 모양을 맞추었을 때, 게임 종료
*/

using namespace std;

class isNotMovable { };

class Puzzle {
	int cell[3][3];
	int x, y;
	void shuffle();
	void convert(int& a, int& b);
	// bool isMovable();
public:
	Puzzle();
	void move(char c);
	bool isDone();
	friend ostream& operator<<(ostream& os, Puzzle& pz);
};

/* class Puzzle 구현 */
Puzzle::Puzzle() {
	x = 2;
	y = 2;

	int num = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cell[i][j] = num;
			num++;
		}
	}
	cell[2][2] = 0;

	shuffle();
}

void Puzzle::shuffle() {
	srand(time(NULL));
	int rn;
	for (int i = 0; i < 4; i++) {
		rn = rand() % 4;
		try {
			switch (rn) {
			case 0:
				move('u');
				break;
			case 1:
				move('d');
				break;
			case 2:
				move('l');
				break;
			case 3:
				move('r');
				break;
			
			}

		}
		catch (isNotMovable& e) {

		}
	}
}

void Puzzle::convert(int& a, int& b) {
	a = b;
	b = 0;
}


void Puzzle::move(char c) {
	
	switch(c) {
	case 'u':
		if (y == 0) { throw isNotMovable(); }
		convert(cell[x][y], cell[x - 1][y]);
		y--;
		break;
	case 'd':
		if (y == 2) { throw isNotMovable(); }
		convert(cell[x][y], cell[x + 1][y]);
		y++;
		break;
	case 'l':
		if (x == 0) { throw isNotMovable(); }
		convert(cell[x][y], cell[x][y - 1]);
		x--;
		break;
	case 'r':
		if (x == 2) { throw isNotMovable(); }
		convert(cell[x][y], cell[x][y + 1]);
		x++;
		break;
	}

}

// 아 여기가 조금 문제네 내 방식대로 하면..
bool Puzzle::isDone() {
	int num = 1;
	if (cell[2][2] != 0) {
		return false;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (cell[i][j] != num) {
				return false;
			}
		}
	}

	return true;
}

ostream& operator<<(ostream& os, Puzzle& pz) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << pz.cell[i][j];
		}
		os << endl;
	}
	return os;
}

int main() {
	
	Puzzle pz;

	cout << pz;

	while (!pz.isDone()) {
		char c;
		cout << "choice movement: ";
		cin >> c;
		try {
			pz.move(c);
			cout << pz;
		}
		catch (isNotMovable& e) {

		}
	}
	cout << "It's Done!" << endl;

	return 0;
}