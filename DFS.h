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
    list<State<T> *> adjList;
public:
    S search(ISearchable<T> *searchable) {
        //getting the first vertex to start from
        State<T> *startState = searchable->getInitialState();
        //we will run DFS by using a stack
        //we will path state and searchable (our matrix or graph)
        int totalNumOfNodes = runDFS(startState, searchable);
        return totalNumOfNodes;
    }

    int runDFS(State<T> *startState, ISearchable<T> *searchable) {
        // we set the adjacent list of the source vertex
        adjList = searchable->getAllPossibleStates(startState);
        // Mark all the vertices as not visited
        bool *visited = new bool[adjList.size()];
        for (int i = 0; i < adjList.size(); i++) {
            visited[i] = false;
        }
        // Mark the current node as visited and enqueue it
        visited[startState] = true;
        // add the source node to the open list which is a stack data structure
        addToOpenList(startState);
        // create an iterator to iterate through the adjacency list
        typename std::list<State<T> *>::iterator i;
        // while the stack is not empty
        while (this->openList.size() > 0) {
            // Pop a vertex from stack
            State<T> *u = this->openList.top();
            this->openList.pop();
            // if the popped state was not visited marked it
            if (!visited[u]) {
                // increase the number of visited nodes
                this->evaluatedNodes++;
                visited[u] = true;
            }
            // Get all adjacent vertices of the popped vertex u
            // If a adjacent has not been visited, then push it
            // to the stack.
            for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i) {
                if (!visited[*i]) {
                    this->openList.push(*i);
                }
            }
        }
        // return the total number if nodes that the algorithm passed
        return this->evaluatedNodes;
    }
};

#endif //PART2_DFS_H
