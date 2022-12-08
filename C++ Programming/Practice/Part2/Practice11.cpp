#include <iostream>
#include <vector>

// 클래스는 객체

using namespace std;

class Board {
	vector<vector<int>> board;
	int width;
	int height;
public:
	Board(vector<vector<int>> b);
	int solution();
};

/* class Board 구현 */
Board::Board(vector<vector<int>> b) {
	board = b;
	width = board[0].size();
	height = board.size();
}

int Board::solution() {

}

int main() {

}