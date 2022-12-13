#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

/* 
	Puzzle 게임 구현
*/


using namespace std;

class isNotMovable { };

class Puzzle {
	int cell[9];
	int x, y;
	void shuffle();
	int convert(int x, int y);
public:
	Puzzle();
	void move(char c);
	bool isDone();
	friend ostream& operator<<(ostream& os, Puzzle& pz);
};

/* class Puzzle 구현 */
Puzzle::Puzzle() {
	for (int i = 0; i < 8; i++) {
		cell[i] = i + 1;
	}
	cell[8] = 0;
	x = 2;
	y = 2;
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

int Puzzle::convert(int x, int y) {
	return 3 * y + x;
}

void Puzzle::move(char c) {
	int from = convert(x, y);
	int to;
	switch (c) {
	case 'u':
		if (y == 0) { throw isNotMovable(); };
		to = convert(x, y - 1);
		cell[from] = cell[to];
		cell[to] = 0;
		y--;
		break;
	case 'd':
		if (y == 2) { throw isNotMovable(); };
		to = convert(x, y + 1);
		cell[from] = cell[to];
		cell[to] = 0;
		y++;
		break;
	case 'l':
		if (x == 0) { throw isNotMovable(); };
		to = convert(x - 1, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x--;
		break;
	case 'r':
		if (x == 2) { throw isNotMovable(); };
		to = convert(x + 1, y);
		cell[from] = cell[to];
		cell[to] = 0;
		x++;
		break;
	default:
		throw isNotMovable();
	}
}

bool Puzzle::isDone() {
	for (int i = 0; i < 8; i++) {
		if (cell[i] != i + 1) {
			return false;
		}
	}
	if (cell[8] != 0) {
		return false;
	}
	return true;
}

ostream& operator<<(ostream& os, Puzzle& pz) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			os << pz.cell[k++] << ' ';
		}
		os << endl;
	}
	return os;
}

int main() {

	Puzzle myPuzzle;
	cout << myPuzzle;
	while (!(myPuzzle.isDone())) {
		char c;
		cout << "Choice Movement: ";
		cin >> c;
		try {
			myPuzzle.move(c);
			cout << myPuzzle;
		}
		catch (isNotMovable &e) {

		}
	}
	cout << "It's Done" << endl;

	return 0;

}