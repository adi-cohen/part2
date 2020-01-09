//
// Created by adi on 08/01/2020.
//
#include <string>
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"
#include "ClientHandler.h"
#include "CacheManager.h"

#ifndef PART2_MYTESTCLIENTHANDLER_H
#define PART2_MYTESTCLIENTHANDLER_H


class MyTestClientHandler : public ClientHandler{
private:
    Solver* solver;
    CacheManager* chacheMenager;
public:
    MyTestClientHandler(Solver* sol, CacheManager* cache){
        this->solver=sol;
        this->chacheMenager=cache;
    }
    void handleClient(int socket) override ;
};

//template <typename Problem, typename Solution>

//class myTestClientHandler : public ClientHandler {
//    CacheManager manager;
//    Solver<Solution,Problem> *solver;
//    //Solver<std::string, std::string> solver;
//public:
//    int handleClient(server_side:: mySocket in, server_side::mySocket out) override;
//    myTestClientHandler(CacheManager cm, Solver<Solution,Problem> sol){
//        this->manager=cm;
//        this->solver=sol;
//    }
//};


#endif //PART2_MYTESTCLIENTHANDLER_H
