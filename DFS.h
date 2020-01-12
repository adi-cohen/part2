//
// Created by adi on 11/01/2020.
//

#ifndef PART2_DFS_H
#define PART2_DFS_H

#include "ISearchable.h"
#include "StackSearcher.h"
#include <deque>
#include "cmath"
#include "list"


using namespace std;


template<class S, class T>
class DFS : public StackSearcher<solution, T> {
private:
    int pathCount;
    list<State<T> *> pathList;
    list<State<T> *> adjList;
public:
    S search(ISearchable<T> *searchable) {
        //getting the first vertex to start from

        State<T> *startState = searchable->getInitialState();
        runDFS(startState, searchable);
        //todo here pathlist is string and we return list
        return pathList;
    }

    void runDFS(State<T> *currentState, ISearchable<T> *searchable) {
        this->openList.push_back(currentState);
        addToOpenList(currentState);
        adjList = searchable->getAllPossibleStates(currentState);
        //if there is no more adj to visit
        if (adjList.empty() & !searchable->isGoalState(currentState)) {
            //we will remove the current node from the list and return from the recursion
            this->openList.pop();
            return;
        }
        typename std::list<State<T> *>::iterator it;
        for (it = adjList.begin(); it != adjList.end(); ++it) {
            //if one of the adj is the goal
            if (searchable->isGoalState(*it)) {
                //we will add the goal to the list
                this->addToOpenList(*it);
                //we need to check if the current path is the shortest path
                int currentCount = 0;
                typename std::list<State<T> *>::iterator countIt;
                for (it = this->openList.begin(); it != this->openList.end(); ++it) {
                    State<T> *state = *it;
                    currentCount += state->getCost();
                }
                if (currentCount < pathCount) {
                    //if its the shortest path
                    pathCount = currentCount;
                    pathList = this->openList;
                    this->popOpenList();
                    return;
                }
            }
            //we will check if the adj is in the visited list
            bool isInList = false;
            typename std::list<State<T> *>::iterator k;
            for (k = adjList.begin(); k != adjList.end(); ++k) {
                if (*it == *k) {
                    isInList = true;
                }
            }
            if (!isInList) {
                runDFS(*it, searchable);
            }
        }
    }

};

#endif //PART2_DFS_H
