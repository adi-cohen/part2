//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_STRINGREVERSER_H
#define PART2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
#include <iostream>
using namespace std;
class StringReverser: public Solver {
public:
    // implements the virtual function of Solver abstract class - solve()
    string solve(string str) {
        string reverse;
        for(string::iterator it = str.end(); it != str.begin(); it--) {
            if(*it == '\\') {
                break;
            }
            reverse += *it;
        }
        cout << "Problem was solved by the string reverser";
        return reverse;
    }
};
#endif //PART2_STRINGREVERSER_H
