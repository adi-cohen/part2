//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_DFS_H
#define PART2_DFS_H
#include "ISearchable.h"
#include "StackSearcher.h"
#include <deque>
using namespace std;


template<class solution, class T>
class DFS : public StackSearcher<solution, T> {
public:

    solution search(ISearchable<T> *searchable) {


    }
};
#endif //PART2_DFS_H
