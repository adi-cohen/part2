//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_ISEARCHER_H
#define PART2_ISEARCHER_H
#include "ISearchable.h"
#include <vector>

  // The following interface represent the algorithm itself which takes part of the bridge design pattern.
  // we use the dependency injection so we can solve any kind of search problem by different search algorithms.
template <class solution,class T>
class ISearcher {
public:
    virtual solution search (ISearchable<T>* searchable) = 0; // the search method - dependency injection
    virtual int getNumberOfNodesEvaluated() = 0; // get how many nodes were evaluated by the algorithm
    virtual int getPathLength() = 0; // get how many nodes were evaluated by the algorithm
};

#endif //PART2_ISEARCHER_H
