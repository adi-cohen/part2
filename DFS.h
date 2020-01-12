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
        //we will run DFS recursively
        //we will path state and searchable (our matrix or graph)
        runDFS(startState, searchable);
        //todo here pathlist is string and we return list
        return pathList;
    }

    void runDFS(State<T> *currentState, ISearchable<T> *searchable) {
        //here the open list using to save the path we went through
        //on each iteration we add the current state to tha openList
        addToOpenList(currentState);
        //we create a list of vertex that adjacent to the current state
        adjList = searchable->getAllPossibleStates(currentState);
        //if there is no more adj to visit and we are not in the goal state
        if (adjList.empty() & !searchable->isGoalState(currentState)) {
            //we will remove the current node from the list and return from the recursion
            this->openList.pop();
            currentState->deleteCameFrom();
            return;
        }
        typename std::list<State<T> *>::iterator it;
        //for each adjacent in the list
        for (it = adjList.begin(); it != adjList.end(); ++it) {
            //option 1 - if one of the adj is the goal
            State<T>* adjState = *it;
            if (searchable->isGoalState(adjState)) {
                //we will add the goal to the list
                //now the open list contains path from start state to goal state
                this->addToOpenList(adjState);
                adjState->setCameFrom(currentState);
                //we need to check if the current path is the shortest path
                //we calculate the current path according to the open list that holding the path
                int currentCount = 0;
                typename std::list<State<T> *>::iterator countIt;
                for (it = this->openList.begin(); it != this->openList.end(); ++it) {
                    State<T> *state = *it;
                    currentCount += state->getCost();
                }
                // if we got shortest path from start state to goal state
                if (currentCount < pathCount) {
                    //we will update our information about the shortest path
                    pathCount = currentCount;
                    pathList = this->openList;
                    // we remove the goal state to check if there is better path
                    this->popOpenList();
                    adjState->deleteCameFrom();
                    return;
                }
            }
            //option 2 - we will check if the adj is in the visited list
            bool isInList = false;
            typename std::list<State<T> *>::iterator k;
            for (k = adjList.begin(); k != adjList.end(); ++k) {
                if (*it == *k) {
                    isInList = true;
                }
            }
            //if the state isn't in the open list it mean we didn't visit him yet
            //we will tun DFS on this state
            if (!isInList) {
                State<T>* newState = *it;
                //we define the camefrom state;
                newState->setCameFrom(currentState);
                runDFS(*it, searchable);
            }
        }
    }

};

#endif //PART2_DFS_H
