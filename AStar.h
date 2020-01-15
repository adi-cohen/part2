//
// Created by yaron on 13/01/2020.
//

#ifndef PART2_ASTAR_H
#define PART2_ASTAR_H
#include "PrioritySearcher.h"


// This class implements the PrioritySearcher abstract class as a A* algorithm
template<class S, class T>
class AStar : public PrioritySearcher<S, T> {
public:
    // This method gets a searchable problem runs the A* algorithm and returns the minimal path it found
   S search(ISearchable<T> *searchable) {
       // getting the source vertex
       State<T> *initState = searchable->getInitialState();
       // we set the vertex s: s.f = s.g + s.h
       initState->setCost(initState->getCost() + getManDist(initState, searchable->getGoalState()));
       // we enqueue the first vertex s to the open queue
       PrioritySearcher<S, T>::addToOpenList(initState);
       // creates the closed queue
       multiset<State<T> *, CompareCost<T>> closed;
       // while the open queue isn't empty
       while (PrioritySearcher<S, T>::openList.size() > 0) {
           // inherited from PrioritySearcher, removes the least state
           State<T>* n = PrioritySearcher<S, T>::popOpenList();
           closed.insert(n); // We insert it into the close list so it won't be processed again
           // If we have reached the goal state we will trace back the path we have found and return it
           if (searchable->isGoalState(n))
           {
               // We decrease the last heuristic from the goal state: n
               n->setCost(n->getCost() - getManDist(n,searchable->getGoalState()));
               // back traces through the parents
               //return PrioritySearcher<solution, T>::backTrace(n,searchable);
               // return the total number if nodes that the algorithm passed (int)
               return this->evaluatedNodes;
           }
           // calling the delegated method, returns a list of states with n as a parent
           list<State<T>*> successors = searchable->getAllPossibleStates(n);
           // We iterate through all the successors state
           for (auto it = successors.begin(); it != successors.end(); it++) {
               State<T>* s = *it;
               // if the state isn't found in the open list and also the not in the closed list we will add it to the open list
               if ((!isInSet(PrioritySearcher<S, T>::openList,s)) && (!(isInSet(closed,s)))) {
                   // We add to the cost of each state his distance from the goal state and decrease the distance
                   // from goal state from his parent state
                   s->setCost(s->getCost() + getManDist(s,searchable->getGoalState()) - getManDist(n,searchable->getGoalState()));
                   this->addToOpenList(s);
               }

               // if the state wasn't found in the closed list but was found in the open list, we will check if it has smaller
               // cost then what is already found in the open list and if it has we will replace the old cost with the new one
               else if (!(isInSet(closed,s)))
               {
                   saveMin(s);
               }
           }
       }
   }

    // THE HEURISTIC METHOD - This method calculates the Manhattan distance of a state from the goal state and returns it
    int getManDist(State<T>* currState, T goalState) {
        int xDist = goalState[0] - currState->getState()[0];
        int yDist = goalState[1] - currState->getState()[1];
        return abs(xDist) + abs(yDist);
    }

    // This method checks if a state is found in the open list, and if it's cost is smaller then the state inside
    // the open list we will replace it's cost with the new cost
    virtual void saveMin(State<T>* currState)
    {
        for (auto it = PrioritySearcher<S,T>::openList.begin(); it != PrioritySearcher<S,T>::openList.end(); it++)
        {
            State<T>* s = *it;
            if(s->Equals(currState))
            {
                if (currState->getCost() < s->getCost())
                {
                    PrioritySearcher<S,T>::openList.erase(it);
                    this->addToOpenList(currState);
                }
                return;
            }
        }
        this->addToOpenList(currState);
        return;
    }

    // This method checks if a state is inside a multiset
    bool isInSet(multiset<State<T>*,CompareCost<T>> setOfState,State<T>* currState)
    {
        for (auto it = setOfState.begin(); it != setOfState.end(); it++)
        {
            State<T>* s = *it;
            if(s->Equals(currState))
                return true;
        }

        return false;
    }

};
#endif //PART2_ASTAR_H
