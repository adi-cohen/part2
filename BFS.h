//
// Created by yaron on 12/01/2020.
//

#ifndef PART2_BFS_H
#define PART2_BFS_H

#include "QueueSearcher.h"

template < class T, class solution >
class BFS : public QueueSearcher<solution, T> {
private:
    // the adjancet list of the source vertex
    list<State<T> *> adjList;
public:
    solution search(ISearchable<T> *searchable) {
        // getting the source vertex
        State<T> *startState = searchable->getInitialState();
        // run the main function of the BFS
        int totalNumOfNodes = runBFS(startState, searchable);
        return totalNumOfNodes;
    }

    int runBFS(State<T>* startState, ISearchable<T> *searchable) {
        // we set the adjacent list of the source vertex
        adjList = searchable->getAllPossibleStates(startState);
        // Mark all the vertices as not visited
        bool *visited = new bool[adjList.size()];
        for(int i = 0; i < adjList.size(); i++) {
            visited[i] = false;
        }
        // Mark the current node as visited and enqueue it
        visited[startState] = true;
        // Q <- enqueue(s)
        addToOpenList(startState);
        // 'i' will be used to get all adjacent
        // vertices of a vertex
        typename std::list<State<T> *>::iterator i;
        // while the queue is not empty
        while(this->openList.size() > 0) {
            // Dequeue a vertex from queue
            State<T>* u = this->openList.front();
            this->openList.pop_front();
            // Get all adjacent vertices of the dequeue
            // vertex u. If a adjacent has not been visited,
            // then mark it visited and enqueue it
            for(i = adjList[u].begin(); i != adjList.end(); i++) {
                // if the adjacent was not visited
                if (!visited[*i])
                {
                    // increase the number of visited nodes
                    this->evaluatedNodes++;
                    // set where it came from
                    State<T>* neighbor = *i;
                    neighbor->setCameFrom(u);
                    // mark it as visited
                    visited[*i] = true;
                    this->openList.push_back(*i);
                }
            }
        }
        // return the total number if nodes that the algorithm passed
        return this->evaluatedNodes;
    }

};

#endif //PART2_BFS_H
