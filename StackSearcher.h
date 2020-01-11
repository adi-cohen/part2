//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_STACKSEARCHER_H
#define PART2_STACKSEARCHER_H
#include "Isearcher.h"
#include "Solution.h"
#include "stack"

/*
 * This class extends the ISearcher interface, and represents an abstract class of an algorithm
 * which solve a search problem using a stack
 */
template <class T, class solution>
class StackSearcher : public ISearcher< solution , T >{
protected:
    stack<State < T >*> openList; // This stack holds the states/nodes which are waiting to be processed
    int evaluatedNodes; // number of nodes evaluated by the algorithm
    int pathLength; // represents the length of the min path which was found by the algorithm

    /* When we will want to insert a state to the open list we will push it to the front of the
    * list to represents pushing an object to a stack
    */
    void addToOpenList(State <T> *s) {
        this->openList.push(s);
    }
    /* When we will want to extract a state from the open list we will return it and erase him from the list
    * to represents popping an object from a stack
    */
    State<T>* popOpenList() {
        evaluatedNodes++;
        State<T> *s = this->openList.top();
        this->openList.pop();
        return s;
    }
public:
    // constructor
    StackSearcher() {
        evaluatedNodes = 0;
    }
    // will be implement by a specific algorithm (like BFS)
    virtual solution search (ISearchable<T>* searchable) = 0;
    // get how many nodes were evaluated by the algorithm
    int getNumberOfNodesEvaluated()
    {
        return evaluatedNodes;
    }
    // This method returns what is the the minimum path we found using the algorithm
    virtual int getPathLength()
    {
        return pathLength;
    }

    // This method traces back the path the algorithm found, and returns which steps were taken on this path
    solution backTrace(State<T>* currState, ISearchable<T> *searchable) {
        deque<string> path;
        string ans = "";
        this->pathLength = currState->getCost();
        State<T> *initState = searchable->getInitialState();
        while (!(currState->Equals(initState))) {
            path.push_front(currState->getCameFromDir());
            currState = currState->getCameFrom();
        }

        auto it = path.begin();
        ans += *it;
        it++;

        for (; it != path.end(); it++) {
            ans += ",";
            ans += *it;
        }
        return ans;
    }
};
#endif //PART2_STACKSEARCHER_H
