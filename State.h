//
// Created by yaron on 10/01/2020.
//

#ifndef PART2_STATE_H
#define PART2_STATE_H
#include <string>
using namespace std;

template <class T>
class State {
    T state; // the state represented by a string
    int cost; // cost to reach this state (set by a setter)
    State<T>* cameFrom; // the state we came from to this state (setter)
    string cameFromDir; // the direction it came from
public:
    // constructor
    State<T>(T state, int cost, State<T>* cameFrom,string cameFromDir)
    {
        this->state = state;
        this->cost = cost;
        this->cameFrom = cameFrom;
        this->cameFromDir = cameFromDir;
    }

    // we override Object's Equals method
    bool Equals(State<T>* other)
    {
        if (this->state == other->state)
            return true;
        else
            return false;
    }

    int getCost()
    {
        return this->cost;
    }

    void setCost(int cost)
    {
        this->cost = cost;
    }

    void setCameFrom(State<T>* state)
    {
        this->cameFrom = state;
    }

    State<T>* getCameFrom()
    {
        return cameFrom;
    }

    T getState()
    {
        return this->state;
    }

    string getCameFromDir()
    {
        return this->cameFromDir;
    }

    void setState(string direction)
    {
        this->cameFromDir = direction;
    }
};
#endif //PART2_STATE_H
