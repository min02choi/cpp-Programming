#include <iostream>
#include <vector>

// status: 200

/*
	어디서 어디로 이동했다는 것을 Path에 저장(Path는 하나의 이동임, 총 4개의 매개변수)
	이 정보(Path)들을 묶음으로 저장 -> PathQue: 전체 경로가 저장되게 됨

	이번에 이동하는 경로가 있으면, 이전의 PathQue에서 Path를 하나씩 다 검사(현재 Path와 이전의 Path가 동일한가?)
*/

using namespace std;

class outOfBound { };

class Path {
	int x1, x2, y1, y2;
public:
	Path(int xx1, int xx2, int yy1, int yy2);
	friend bool operator==(Path& a, Path& b);
};

class PathQue {
	vector<Path> paths;
	bool isIn(Path& a);
public:
	void push(Path& a);
	int count();
};

class MyGame {
	int x, y;
	PathQue myQue;
	void move(char c);
public:
	MyGame();
	int getX();
	int getY();
	void move(string& commands);
	int getCount();
};

/* class Path 구현 */
Path::Path(int xx1, int xx2, int yy1, int yy2) {
	x1 = xx1;
	x2 = xx2;
	y1 = yy1;
	y2 = yy2;
}

bool operator==(Path& a, Path& b) {
	if (a.x1 == b.x1 && a.y1 == b.y1 && a.x2 == b.x2 && a.y2 == b.y2) {
		return true;
	}
	else if (a.x1 == b.x2 && a.y1 == b.y2 && a.x2 == b.x1 && a.y2 == b.y1) {
		return true;
	}
	return false;
}

/* class PathQue 구현 */
bool PathQue::isIn(Path& a) {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i] == a) {	// 이미 중복된것
			return true;		// 이미 있음
		}
	}
	return false;		// 이전 경로에 없음
}

void PathQue::push(Path& a) {
	if (!isIn(a)) {		// 이전경로에 없으면 넣어줌
		paths.push_back(a);
	}
}

int PathQue::count() {
	return paths.size();
}

/* class MyGame 구현 */
MyGame::MyGame() {
	x = 0;
	y = 0;
}

void MyGame::move(char c) {
	switch (c) {
	case('U'):
		if (y == 5) { throw outOfBound(); }
		else { y++; }
	case('D'):
		if (y == -5) { throw outOfBound(); }
		else { y--; }
	case('R'):
		if (x == 5) { throw outOfBound(); }
		else { x++; }
	case('L'):
		if (x == -5) { throw outOfBound(); }
		else { x--; }
	}
	
}

int MyGame::getX() {
	return x;
}

int MyGame::getY() {
	return y;
}

void MyGame::move(string& commands) {
	for (int i = 0; i < commands.length(); i++) {
		try {
			// move(commands[i]);	// 이거 아닌거같은데
			int preX = x;
			int preY = y;
			move(commands[i]);
			Path temp(preX, preY, x, y);
			myQue.push(temp);
		}
		catch (outOfBound& e) {

		}
	}
}

int MyGame::getCount() {
	return myQue.count();
}


int main() {

	string commands1 = "LULLLLLLU";
	string commands2 = "ULURRDLLU";

	MyGame mygame1, mygame2;

	mygame1.move(commands1);
	mygame2.move(commands2);

	cout << mygame1.getCount() << endl;
	cout << mygame2.getCount() << endl;

	return 0;
}