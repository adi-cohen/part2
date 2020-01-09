//
// Created by adi on 08/01/2020.
//

#ifndef PART2_SOLVER_H
#define PART2_SOLVER_H

// will receive a generic problem and solution
template <class Problem, class Solution>
class solver {
public:
    virtual Solution solve(Problem) = 0;
    virtual ~solver() {};
};


#endif //PART2_SOLVER_H
