//
// Created by adi on 13/01/2020.
//

#ifndef PART2_MATRIXSOLVERBESTFS_H
#define PART2_MATRIXSOLVERBESTFS_H

#include "Solver.h"
#include "ISearchable.h"
#include "Isearcher.h"
#include "BestFirstSearch.h"

// will receive a generic problem and solution
//template<class P, typename S, typename T>
class MatrixSolverBestFS : public Solver<MatrixProblem, string> {
private:
    ISearcher<string, pair<int, int>> *searcher = new BestFirstSearch<string, pair<int,int>>();

    ISearchable<pair<int, int>>* searchableMatrix;
public :

    string solve(MatrixProblem problem) override {
        return this->searcher->search(&problem);
    }

};

#endif //PART2_MATRIXSOLVERBESTFS_H
