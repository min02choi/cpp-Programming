#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

class Reading {
public:
	int hour;
	double temperature;
};

int main() {

	vector<Reading> temps;
	ifstream ist{ "sample.txt" };
	int hour;
	double temperature;
	while (ist >> hour >> temperature) {
		if (hour < 0 || 23 < hour) {
			cout << "hour out of range" << endl;
		}
		cout << hour << ", " << temperature << endl;
		temps.push_back(Reading{ hour, temperature });
	}

	return 0;
}