#include <iostream>
#include <vector>

/*
	2022 2�б� C++ ������ ����
*/

// Ŭ���� ���� ���� ����

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

/* class Path ���� */
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

/* class myGame ���� */
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

/* class PathQue ���� */
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
	C++ �����, C++ �� ����

	[ encapsulization(ĸ��ȭ, ���ȭ) ]
	- ������ ��������� ���еǴ� �κ��� class�� �������� ������ ��
	- ������ Ŭ������ ���� Ŭ������ ���� ����.
	- ���ȭ -> ���� ������ ����
	- �� input�� ���ؼ��� Ư�� output�� ��ȯ�ϸ� ��

	[ ploymorphism(������) ]
	- ���������� ���� ����� �ϸ� ���� �̸��� ����ϴ� ���� �������

	[ interitance(���) ]
	- ������ �ڵ忡�� �ٲ��� ���ƾ� �� �κ��� �״�� ���� �����ϰԲ� ��
	- ���꼺�� ���
	- �ߺ� �ڵ��� ������, �ڵ��� ������ ü��ȭ������
	- �Ϻ� �ڵ��� ������ ���� ��� ctrl + c,v �� �ʿ䰡 ������
*/

// ������, ĸ��ȭ, ���
// �������


/*
	1. friend bool operator==(Path& a, Path& b);
	�̋� �� friend�� ���?
*/