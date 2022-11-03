// friend functions
#include <iostream>

using namespace std;

class CRectangle {
	int width, height;

public:
	void set_values(int, int);
	int area() {
		return(width * height);
	}
	friend CRectangle duplicate(CRectangle);
};