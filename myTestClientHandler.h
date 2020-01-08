//
// Created by adi on 08/01/2020.
//
#include <string>
#include "Solver.h"
#include "CachManager.h"
#include "FileCacheManager.h"
#include "ClientHandler.h"

#ifndef PART2_MYTESTCLIENTHANDLER_H
#define PART2_MYTESTCLIENTHANDLER_H

class myTestClientHandler : public ClientHandler {
    FileCacheManager *manager;
    solver<std::string, std::string> *solve;
public:
    // will use the class mySocket to read the input of the client by the method - readIn()
    // after checking in the cache or solve it by the solver we will send 'out' variable to the client as a solution...
    int handleClient(server_side:: mySocket in, server_side::mySocket out) {
        std::string input;
        // calling the method readIn in mySocket class - if the read was accomplished
        if (in.readIn(&input)) {
            // if the read of the input client's was read,
            // we should check in the cache manager if there is any solution for this string
            //todo - methods in cache manger like: isSaved(), getSolution() etc.
        }
    }
};
#endif //PART2_MYTESTCLIENTHANDLER_H
