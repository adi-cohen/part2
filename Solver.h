//
// Created by adi on 08/01/2020.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H

#include "Problem.h"
#include "Solution.h"
#include "string.h"
#include "Isearcher.h"

using namespace std;
// will receive a generic problem and solution
template <typename P, typename S>
class Solver{
public:
    P problem;
    S solution;
public:
    // virtual string solve(string problem) = 0;
    virtual S solve(P) = 0;
    // new
    //virtual Solver* clone() = 0;
    //virtual ~Solver(){};
};

#endif //PART2_SOLVER_H
