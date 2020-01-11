//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_MATRIXPROBLEM_H
#define PART2_MATRIXPROBLEM_H
#include "ISearchable.h"
#include <list>
#include <vector>
#include <iostream>

using namespace std;

// The following class implements the interface Isearchable, and represents the problem
// of find the shortest path in a matrix maze.
class matrixProblem : public ISearchable <vector< int >> {
public:
    // the fields of the class
    vector<vector<int>> matrix; // represents the matrix as vector of vector of ints
    int length;
    int width;
    vector<int> initState; // the source/enter state
    vector<int> goalState; // the goal/exit state
public:

    // constructor
    matrixProblem(vector<string> mat, vector<int> initState, vector<int> goalState) {

    }

    //  Inherited from ISearchable - the following method creates the initial state and returns it
    virtual State<vector<int>>* getInitialState() {
        State<vector<int>>* s = new State<vector<int>>(initState,0,NULL,"");
        return s;
    }

    // Inherited from ISearchable - return the size of the matrix
    virtual int getProblemSize() {
        int matrixSize = length * width;
        return matrixSize;
    }

    // Inherited from ISearchable - getter for the goal state
    virtual vector<int> getGoalState()
    {
        return goalState;
    }

    // Inherited from ISearchable - check if the current state is the goal state
    virtual bool isGoalState(State<vector<int>>* currentState) {
        if(currentState->getState() == goalState) {
            return true;
        } else {
            return false;
        }
    }
};


#endif //PART2_MATRIXPROBLEM_H
