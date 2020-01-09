//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_PROBLEM_H
#define PART2_PROBLEM_H
#include <string>
class problem {
    // the following field is the problem's name
private:
    std::string representation;
public:
    problem(std::string str) {
        representation = str;
    }
    std::string represent() { return representation;};
};
#endif //PART2_PROBLEM_H
