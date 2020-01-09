//
// Created by yaron on 08/01/2020.
//

#ifndef PART2_MYSERIALSERVER_H
#define PART2_MYSERIALSERVER_H

#include <thread>
#include "Server.h"
#include "ClientHandler.h"

//using namespace server_side;
class mySerialServer: public server {
private:
    bool stopper;
public:
    mySerialServer() {return;}
    ~mySerialServer() {return;}
    int open(int port, ClientHandler* handler);
    int close();
};
//using namespace server_side;

#endif //PART2_MYSERIALSERVER_H
