//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_SOLUTION_H
#define PART2_SOLUTION_H
#include <string>
class solution {
    // the following field is the solution's name
private:
    std::string representation;
public:
    solution(std::string str) {
        representation = str;
    }
    std::string represent() { return representation;}
};
#endif //PART2_SOLUTION_H
