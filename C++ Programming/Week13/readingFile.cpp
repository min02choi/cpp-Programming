#include <iostream>
#include <string>
#include <vector>
#include <fstream>


/*
    에러뜸 수정할 것
    뭔소린지
*/

using namespace std;

class Reading {
public:
    int hour;
    double temperature;
};

void fill_vector(istream& ist, vector<int>& v, char terminator) {
    // read integers from ist into v until we reach eof() or terminator
    for (int i; ist >> i; ) {   // read until “some failure”
        v.push_back(i);            // store in v
        // cout << i << endl;
    }
    if (ist.eof()) return;              // fine: we found the end of file
    if (ist.bad()) cout << "ist is bad" << endl; // stream corrupted; let’s get out of here!

    if (ist.fail()) {     // clean up the mess as best we can and report the problem
        ist.clear();      // clear stream state, so that we can look for terminator
        char c;
        ist >> c;         // read a character, hopefully terminator

        if (c != terminator) {            // unexpected character
            ist.unget();                  // put that character back
            ist.clear(ios_base::failbit); // set the state back to fail()
        }
    }
}