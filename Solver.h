//
// Created by adi on 08/01/2020.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H

#include "Problem.h"
#include "Solution.h"
#include "string.h"
using namespace std;
// will receive a generic problem and solution
template <class P, typename S>
class Solver{

public:
   // virtual string solve(string problem) = 0;
    virtual S solve(P) = 0;
};

#endif //PART2_SOLVER_H
