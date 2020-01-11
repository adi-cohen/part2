//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_BESTFIRSTSEARCH_H
#define PART2_BESTFIRSTSEARCH_H
#include "ISearchable.h"
#include "PrioritySearcher.h"
#include <unordered_set>
#include <deque>
using namespace std;

// The following class implements the PrioritySearcher abstract class
// as a Best First Search algorithm as we saw in the lecture
template<class solution, class T>
class BestFirstSearch : public PrioritySearcher<solution, T> {
public:

    /*
     * This method gets a searchable problem runs the Best First Search algorithm and returns
     * the minimal path it found
     */
    solution search(ISearchable<T> *searchable) {
        // inherited from PrioritySearcher
        PrioritySearcher<solution, T>::addToOpenList(searchable->getInitialState());
        multiset<State<T> *, CompareCost<T>> closed;
        // while the multi-set OpenList is not empty
        while(PrioritySearcher<solution, T>::openList.size() > 0) {
            // dequeue the top state/node in the multi-set OpenList
            State<T>* n = PrioritySearcher<solution, T>::popOpenList();
            closed.insert(n);
            // if the node n is the goal state
            if(searchable->isGoalState(n)) {
                // we will do back trace and return the solution
                return PrioritySearcher<solution, T>::backTrace(n, searchable);
            }
            // o.w we create a list for all the successors of n
            list<State<T>*> successors = searchable->getAllPossibleStates(n);
            // we iterate over each successor of node n:
            for(auto it = successors.begin(); it != successors.end(); it++) {
                // if the state isn't found in the open list and also the closed list we will add it to the open list
                if ((!isInSet(PrioritySearcher<solution, T>::openList,*it)) && (!(isInSet(closed,*it)))) {
                    // we save the state
                    State<T>* s = *it;
                    // update that we came to s from n
                    s->getCameFrom(n);
                    // and move it to the open list
                    this->addToOpenList(s);

                }
                /* if the state isn't found in the closed list but is found in the open list,
                * we will check if it has smaller
                * cost then what is already found in the open list and if it has we will replace the old cost with
                * the new one
                */
                else if (!(isInSet(closed,*it)))
                {
                    saveMin(*it);
                }

            }
        }
    }
    // The following method checks if a state is found in the open list, and if it's cost is smaller then the state inside
    // the open list we will replace it's cost with the new cost
    virtual void saveMin(State<T>* currState)
    {
        for (auto it = PrioritySearcher<solution,T>::openList.begin(); it != PrioritySearcher<solution,T>
                ::openList.end(); it++) {
            // save the state in s
            State<T>* s = *it;
            if(s->Equals(currState)) {
                // check the costs
                if (currState->getCost() < s->getCost()) {
                    PrioritySearcher<solution,T>::openList.erase(it);
                    this->addToOpenList(currState);
                }
                return;
            }
        }
        this->addToOpenList(currState);
        return;
    }

    // The following method checks if a state is inside a multiset
    // we use it to check if any successor is inside the the open list or the closed list.
    bool isInSet(multiset<State<T>*,CompareCost<T>> setOfState,State<T>* currState) {
        for (auto it = setOfState.begin(); it != setOfState.end(); it++) {
            State<T>* s = *it;
            if(s->Equals(currState))
                return true;
        }
        return false;
    }
};
#endif //PART2_BESTFIRSTSEARCH_H
