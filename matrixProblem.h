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
     /*
     * The constructor of this class gets a matrix which is represented by a vector of strings,
     * the initial state which is represented by vector of int, and a goal state which is represented
     * the same way, the contructor builds a matrix of int using a split function, and
     * sets all of the class members
     */
    matrixProblem(vector<string> stringMatrix, vector<int> initState, vector<int> goalState) {
        // tempMatrix is going to include the values of the input matrix
         vector<vector<int>> tempMatrix;
         // iterate through the vector of strings(the input matrix in the main)
         for (auto it = stringMatrix.begin(); it != stringMatrix.end() ; it++) {
             vector<int> line;
             vector<string> values; // = splitLine(*it,",");
             // iterate over the values of the input string matrix after it was split by ","
             for (auto it = values.begin(); it != values.end(); it++)
             {
                 // convert each value in each line from string to int
                 line.push_back(std::stoi(*it));
             }
             tempMatrix.push_back(line);
         }
         // set the fields of the class:
         this->matrix = tempMatrix;
         this->length = tempMatrix.size();
         this->width = tempMatrix[0].size();
         this->initState = initState;
         this->goalState = goalState;
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
