//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_PRIORITYSEARCHER_H
#define PART2_PRIORITYSEARCHER_H

#include <queue>
#include "Isearcher.h"
#include "State.h"
#include "CompareCost.h"

using namespace std;

template<class S, class T>
class PrioritySearcher : public ISearcher<S, T> {
protected:
    /* This multiset holds the states which are waiting to be processed, it is sorted from the smallest cost
    * to the largest cost to represent an priority queue
    */
    multiset<State<T> *, CompareCost<T>> openList;
    int evaluatedNodes = 0;
    int pathLength = 0;

    /* When we insert a state to the open list we will insert it into the open list
     * and the multiset will sort itself by the CompareCost object function.
     */
    void addToOpenList(State<T> *s) {
        this->openList.insert(s);
    }

    /* When we will want to extract a state from the open list we will erase it from the open list,
     * return it, and the multiset will sort itself accordingly
     */
    State<T> *popOpenList() {
        evaluatedNodes++;
        auto it = openList.begin();
        State<T> *sa = *it;
        openList.erase(it);
        return sa;
    }

public:
    // will be implemented in the Best First Search
    virtual solution search(ISearchable<T> *searchable) = 0; // the search method
    // get how many nodes were evaluated by the algorithm
    int getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }

    // This method returns what is the the min path we found using the algorithm
    virtual int getPathLength() {
        return pathLength;
    }

    // This method traces back the path the algorithm found, and returns which steps were taken on this path
    string backTrace(State<T> *s, ISearchable<T> *searchable) {
        deque<string> path;
        string ans = "";
        // pathLength holds to cost to reach to that state
        this->pathLength = s->getCost();
        State<T> *initState = searchable->getInitialState();
        // while the state isn't the source state
        while (!(s->Equals(initState))) {
            // put in the deque the direction that the state was came from
            path.push_front(s->getCameFromDir());
            // increment the loop by the following command
            s = s->getCameFrom();
        }

        // use an iterator to save the path of the state s
        auto it = path.begin();
        ans += *it;
        it++;

        for (; it != path.end(); it++) {
            ans += ",";
            ans += *it;
        }
        // return the pass of all the states
        return ans;
    }

};

#endif //PART2_PRIORITYSEARCHER_H
