//
// Created by yaron on 10/01/2020.
//

#ifndef PART2_ISEARCHABLE_H
#define PART2_ISEARCHABLE_H
#include <set>
#include <list>
#include "State.h"

template <class T>
class ISearchable {
public:
    virtual State<T>* getInitialState() = 0; // Get the state you want to search a path from
    virtual State<T>* getGoalState() = 0; // returns the state you want to search a path to
    virtual list<State<T>*> getAllPossibleStates(State<T>* s) = 0; // returns all the possible states you can get
    virtual State<T>* getLocationInSearchable(int row, int col) = 0;
    // from an input state
    virtual int getProblemSize() = 0; // returns the size of the problem
    virtual bool isGoalState(State<T>* curState) = 0; // checks if a state is the goal state (for a case we have
    virtual string toString()=0;
    virtual string getDirection(State<pair<int, int>> *currentState, State<pair<int, int>> *previousState)=0;
    // more than one goal state
    virtual ~ISearchable() {}
};
#endif //PART2_ISEARCHABLE_H
