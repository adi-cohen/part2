//
// Created by yaron on 11/01/2020.
//

#ifndef PART2_MATRIXPROBLEM_H
#define PART2_MATRIXPROBLEM_H

#include "ISearchable.h"
#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

// The following class implements the interface Isearchable, and represents the problem
// of find the shortest path in a matrix maze.
class MatrixProblem : public ISearchable<pair<int, int>> {
private:
    vector<vector<State<pair<int, int>> *>> matrix; // represents the matrix as vector of vector of states
    int numOfRow;
    int numOfCol;
    State<pair<int, int>> *initState; // the source/enter state the first int is the row and second the column
    State<pair<int, int>> *goalState; // the goal/exit state the first int is the row and second the column
    pair<int, int> startLocation;
    pair<int, int> endLocation;

public:
    //we will get vector of string
    //each string in the vector represent row in the matrix
    vector<vector<State<pair<int, int>> *>> buildMatrix(vector<string> matrixString, int row, int col) {
        vector<vector<State<pair<int, int>> *>> matrixVector;

        int currentRow;
        int currentCol = 0;
        //for every row we got from the client
        for (currentRow = 0; currentRow < row; currentRow++) {
            vector<State<pair<int, int>> *> lineVector;
            //we get the row as string separated by ","
            //we insert every number to his location.
            string rowString = matrixString.at(currentRow);
            //vector<State<pair<int, int>> *>::iterator currentColIt = lineVector.begin();
            stringstream ss(rowString);
            string valStr;
            //while we have more numbers in the string
            while (getline(ss, valStr, ',')) {
                //remove spaces
                valStr.erase(remove(valStr.begin(), valStr.end(), ' '), valStr.end());
                //convert from string to int
                int cost = stoi(valStr);
                State<pair<int, int>> *currentState;
                currentState = new State<pair<int, int>>(pair<int, int>(currentRow, currentCol), cost);
                //insert the new state to the to the fit col in the line vector
                lineVector.push_back(currentState);
                //*currentColIt.operator->(   ) = currentState;
                //++currentColIt;
                currentCol += 1;
            }
            //insert the row to the matrix
            matrixVector.push_back(lineVector);
        }
        return matrixVector;
    }

// constructor
    MatrixProblem(vector<string> matrixInString, pair<int, int> startLoc, pair<int, int> goalLoc, int matrixRow,
                  int matrixCol) {

        this->numOfCol = matrixCol;
        this->numOfRow = matrixRow;
        this->matrix = buildMatrix(matrixInString, numOfRow, numOfCol);
        this->startLocation = startLoc;
        this->endLocation = goalLoc;
        this->initState = (this->matrix.at(startLocation.first)).at(startLocation.second);
        this->initState = (this->matrix.at(endLocation.first)).at(endLocation.second);
    }


    State<pair<int, int>> *getInitialState() override {
        return this->initState;
    }

    // Inherited from ISearchable - return the size of the matrix
    int getProblemSize() override {
        int matrixSize = this->numOfCol * this->numOfRow;
        return matrixSize;
    }

    // Inherited from ISearchable - getter for the goal state
    State<pair<int, int>> *getGoalState() override {
        return this->goalState;
    }

    // Inherited from ISearchable - check if the current state is the goal state
    bool isGoalState(State<pair<int, int>> *currentState) override {
        if (currentState == goalState) {
            return true;
        } else {
            return false;
        }
    }

    // returns all the possible states you can get from current state
    list<State<pair<int, int>> *> getAllPossibleStates(State<pair<int, int>> *currentState) {
        list<State<pair<int, int>> *> possibleState;
        pair<int, int> currentLocation = currentState->getState();
        int currentRow = currentLocation.first;
        int currentCol = currentLocation.second;
        if (isInMatrixLimits(currentRow + 1, currentCol)) {
            State<pair<int, int>> *upFromCurrentState = getPossitionInMatrix(currentRow + 1, currentCol);
            possibleState.push_back(upFromCurrentState);
        }
        if (isInMatrixLimits(currentRow - 1, currentCol)) {
            State<pair<int, int>> *downFromCurrentState = getPossitionInMatrix(currentRow - 1, currentCol);
            possibleState.push_back(downFromCurrentState);
        }
        if (isInMatrixLimits(currentRow, currentCol - 1)) {
            State<pair<int, int>> *leftFromCurrentState = getPossitionInMatrix(currentRow, currentCol - 1);
            possibleState.push_back(leftFromCurrentState);
        }
        if (isInMatrixLimits(currentRow, currentCol + 1)) {
            State<pair<int, int>> *rightFromCurrentState = getPossitionInMatrix(currentRow, currentCol + 1);
            possibleState.push_back(rightFromCurrentState);
        }
        return possibleState;
    }

    //check if row number and column number is in the matrix limits
    //between 0 to numOfRow/numOfCol.
    bool isInMatrixLimits(int row, int col) {
        if (row <= this->numOfRow & row >= 0) {
            if (col <= this->numOfCol & col >= 0) {
                return true;
            }
        }
        return false;
    }

    //get the state in specific index in the matrix.
    State<pair<int, int>> *getPossitionInMatrix(int row, int col) {
        State<pair<int, int>> *state = (matrix.at(row)).at(col);
        return state;
    }

    //convert the matrix to string for searching in file name
    string toString() {
        string matrixString;
        for (int row = 0; row < numOfRow; row++) {
            for (int col = 0; col < numOfCol; col++) {
                int vertexCost = (matrix.at(row)).at(col)->getCost();
                string vertex = to_string(vertexCost);
                matrixString.append(vertex + ",");
            }
            matrixString.append("\n");
        }
        return matrixString;
    }
};


#endif //PART2_MATRIXPROBLEM_H
