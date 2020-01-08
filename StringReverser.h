//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_STRINGREVERSER_H
#define PART2_STRINGREVERSER_H

#include "Solver.h"
#include <string>
#include <iostream>

class StringReverser: public solver < std::string, std::string > {
public:
    // implements the virtual function of solver abstract class - solve()
    std::string solve(std::string str) {
        std::string reverse;
        for(std::string::iterator it = str.end(); it != str.begin(); it--) {
            if(*it == '\\') {
                break;
            }
            reverse += *it;
        }
        std::cout << "Problem was solved by the string reverser";
        return reverse;
    }
};
#endif //PART2_STRINGREVERSER_H
