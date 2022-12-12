#include <iostream>
#include <vector>

// status: 200

/*
	��� ���� �̵��ߴٴ� ���� Path�� ����(Path�� �ϳ��� �̵���, �� 4���� �Ű�����)
	�� ����(Path)���� �������� ���� -> PathQue: ��ü ��ΰ� ����ǰ� ��

	�̹��� �̵��ϴ� ��ΰ� ������, ������ PathQue���� Path�� �ϳ��� �� �˻�(���� Path�� ������ Path�� �����Ѱ�?)
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

/* class PathQue ���� */
bool PathQue::isIn(Path& a) {
	for (int i = 0; i < paths.size(); i++) {
		if (paths[i] == a) {	// �̹� �ߺ��Ȱ�
			return true;		// �̹� ����
		}
	}
	return false;		// ���� ��ο� ����
}

void PathQue::push(Path& a) {
	if (!isIn(a)) {		// ������ο� ������ �־���
		paths.push_back(a);
	}
}

int PathQue::count() {
	return paths.size();
}

/* class MyGame ���� */
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
			// move(commands[i]);	// �̰� �ƴѰŰ�����
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