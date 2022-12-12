#include <iostream>
#include <vector>

/*
	2022 2학기 C++ 마지막 수업
*/

// 클래스 간의 순서 주의

using namespace std;

////////////////////////////////////////////////////////////////////

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

class myGame {
	int x, y;
	PathQue myQue;
	void move(char c);
public:
	myGame();
	int getX();
	int getY();
	void move(string& commands);
	int getCount();
};

//////////////////////////////////////////////////////////////////

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

/* class myGame 구현 */
myGame::myGame() {
	x = 0;
	y = 0;
}

int myGame::getX() {
	return x;
}

int myGame::getY() {
	return y;
}

void myGame::move(string& commands) {
	for (int i = 0; i < commands.length(); i++) {
		try {
			// move(commands[i]);
			int preX = x;
			int preY = y;
			move(commands[i]);
			Path temp(preX, preY, x, y);
			myQue.push(temp);
		}
		catch (outOfBound &e){

		}
		
	}
}

void myGame::move(char c) {
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

int myGame::getCount() {
	return myQue.count();
}

/* class PathQue 구현 */
void PathQue::push(Path& a) {
	if (!isIn(a)) {
		paths.push_back(a);
	}
}

int PathQue::count() {
	return paths.size();
}

bool PathQue::isIn(Path& a) {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i] == a) {
			return true;
		}
	}
	return false;
}


int main() {
	myGame game;
	string commands = "LULLLLLLU";

	try {
		game.move(commands);
	}
	catch (outOfBound& e) {

	}

	cout << "(" << game.getX() << ", " << game.getY() << ")" << endl;

	Path path1(1, 2, 3, 4), path2(3, 4, 1, 2);
	cout << (path1 == path2) << endl;
	Path path3(1, 2, 3, 4), path4(1, 2, 3, 4);
	cout << (path3 == path4) << endl;
	Path path5(1, 2, 3, 4), path6(3, 4, 1, 1);
	cout << (path5 == path6) << endl;

	Path p1(1, 2, 3, 4),  p2(1, 2, 5, 6), p3(3, 4, 1, 2);
	PathQue myque;
	myque.push(p1);
	myque.push(p2);
	myque.push(p3);

	cout << myque.count() << endl;

	return 0;
}

/*
	C++ 삼대장, C++ 의 위력

	[ encapsulization(캡슐화, 모듈화) ]
	- 각각의 기능적으로 구분되는 부분은 class로 나누어져 구성이 됨
	- 각각의 클래스는 남의 클래스를 알지 못함.
	- 모듈화 -> 유지 보수에 좋음
	- 이 input에 대해서는 특정 output만 반환하면 됨

	[ ploymorphism(다형성) ]
	- 개념적으로 같은 기능을 하면 같은 이름을 사용하는 것을 허용해줌

	[ interitance(상속) ]
	- 기존에 코드에서 바뀌지 말아야 할 부분은 그대로 재사용 가능하게끔 함
	- 생산성의 향상
	- 중복 코딩을 막아줌, 코드의 재사용을 체계화시켜줌
	- 일부 코드의 변동이 생긴 경우 ctrl + c,v 할 필요가 없어짐
*/

// 다형성, 캡슐화, 상속
// 어려워용


/*
	1. friend bool operator==(Path& a, Path& b);
	이떄 왜 friend를 사용?
*/