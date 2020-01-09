//
// Created by adi on 08/01/2020.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H

#include "Problem.h"
#include "Solution.h"
#include "string.h"
using namespace std;
class Solver{
public:
    virtual string solve(string problem) = 0;
};

// will receive a generic problem and solution
//template <typename Problem, typename Solution>
//class Solver {
//    Solution solution;
//    Problem problem;
//public:
//    Solver (Problem pro, Solution sol){
//        this->solution =sol;
//        this->problem=pro;
//    }
//    virtual Solution solve(Problem) = 0;
//    virtual ~Solver() {};
//};


#endif //PART2_SOLVER_H
