//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_COMPARECOST_H
#define PART2_COMPARECOST_H
#include "State.h"

 //This class is an object function which is inserted into the multiset and dictates it sorting method,
 //which is sorting the state from the smallest cost state to the largest cost state.
template <class T>
struct CompareCost {
public:
    bool operator()( State<T>* s1, State<T>* s2) const {
        return  (s1->getCost() < s2->getCost());
    }
};
#endif //PART2_COMPARECOST_H
