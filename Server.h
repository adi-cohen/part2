//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_SERVER_H
#define PART2_SERVER_H
#include "ClientHandler.h"
class server {
public:
    virtual int open(int port, ClientHandler* handler) = 0;
    virtual int stop() = 0;
};

#endif //PART2_SERVER_H
